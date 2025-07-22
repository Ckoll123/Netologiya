#pragma once

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ws2tcpip.h>
#include <winsock2.h>

#pragma comment (lib, "Ws2_32.lib")

using namespace std;


class TCP_Client{
public:
    TCP_Client(){
        int err = WSAStartup(MAKEWORD(2,2), &_wsa_data);

        if (err != 0) {
            cout << "WSAStartup failed: " << err << endl;
            return;
        }

        _socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

        if (_socket == INVALID_SOCKET) {
            cout << "Socket creation failed" << endl;
            WSACleanup();
            return;
        }

        _server_addr.sin_family = AF_INET;
        string ip = "172.0.0.1";
        _server_addr.sin_addr.S_un.S_addr = inet_addr(ip.c_str());
        _server_addr.sin_port = htons(_port);

        int err_s = connect(_socket, (sockaddr*)&_server_addr, sizeof(_server_addr));
        if(err_s == SOCKET_ERROR){
            cout << "Сокет не создан" << endl;
            closesocket(_socket);
            WSACleanup();
            return;
        }

        // int err_s = bind(_socket, (sockaddr*)&_server_addr, sizeof(_server_addr));
        // if(err_s == SOCKET_ERROR){
        //     cout << "Сокет не создан" << endl;
        //     closesocket(_socket);
        //     WSACleanup();
        // }
    }

    ~TCP_Client(){
        closesocket(_socket);
        WSACleanup();
        delete[] _buffer;
    }

    void send_text(){
        int server_size = sizeof(_server_addr);
        string hello = "Hello from TCP client";
        send(_socket, hello.c_str(), hello.size(), 0);
        int size_data = recv(_socket, _buffer, 32, 0);
        if(size_data > 0){
            _buffer[size_data] = '\0';
            cout << _buffer << endl;
        }
    }

private:
    WSAData _wsa_data;
    SOCKET _socket;
    sockaddr_in _server_addr{}, _client_addr{};
    char* _buffer = new char[32];
    int _port = 54321;
};