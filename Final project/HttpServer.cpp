#include "HttpServer.h"

HttpServer::HttpServer(const std::string& address, const std::string& port, const std::string& docRoot, DBcontrol& db) :
    _ioc(1),
    _acceptor(_ioc, {net::ip::make_address(address), static_cast<unsigned short>(std::stoi(port))}),
    _doc_root(std::make_shared<std::string>(docRoot)),
    _db(db)
{}


void HttpServer::execute(){
    for(;;)
    {
        // This will receive the new connection
        tcp::socket socket{_ioc};

        // Block until we get a connection
        _acceptor.accept(socket);

        // Launch the session, transferring ownership of the socket
        std::thread{std::bind(
            &HttpServer::do_session,
            this,
            std::move(socket),
            _doc_root,
            std::ref(_db))}.detach();
    }
}


// Handles an HTTP server connection
void HttpServer::do_session(tcp::socket& socket, std::shared_ptr<std::string const> const& doc_root, DBcontrol& db)
{
    bool close = false;
    beast::error_code ec;

    // This buffer is required to persist across reads
    beast::flat_buffer buffer;

    // This lambda is used to send messages
    send_lambda<tcp::socket> lambda{socket, close, ec};

    for(;;)
    {
        // Read a request
        http::request<http::string_body> req;
        http::read(socket, buffer, req, ec);
        if(ec == http::error::end_of_stream)
            break;
        if(ec)
            return fail(ec, "read");

        // Send the response
        handle_request(*doc_root, std::move(req), lambda, db);
        if(ec)
            return fail(ec, "write");
        if(close)
        {
            // This means we should close the connection, usually because
            // the response indicated the "Connection: close" semantic.
            break;
        }
    }

    // Send a TCP shutdown
    socket.shutdown(tcp::socket::shutdown_send, ec);

    // At this point the connection is closed gracefully
}


// Report a failure
void HttpServer::fail(beast::error_code ec, char const* what)
{
    std::cerr << what << ": " << ec.message() << "\n";
}