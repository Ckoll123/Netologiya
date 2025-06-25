#include <exception>
#include <iostream>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>

#include "Publisher.h"
#include "Book.h"
#include "Shop.h"
#include "Stock.h"
#include "Sale.h"

void fillTables(Wt::Dbo::Session& session);
void getPublisherInfo(Wt::Dbo::Session& session);

int main(){

    try{
        std::string connectionString =
            "host=localhost "
            "port=5432 "
            "dbname=taskwtdbo "
            "user=admin "
            "password=12345";

        auto postgres = std::make_unique<Wt::Dbo::backend::Postgres>(connectionString);
        Wt::Dbo::Session session;
        session.setConnection(std::move(postgres));

        session.mapClass<Publisher>("publisher");
        session.mapClass<Book>("book");
        session.mapClass<Shop>("shop");
        session.mapClass<Stock>("stock");
        session.mapClass<Sale>("sale");

        // session.createTables();

        fillTables(session);
        // getPublisherInfo(session);
    }
    catch (const Wt::Dbo::Exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}


void fillTables(Wt::Dbo::Session& session){
    Wt::Dbo::Transaction transaction{ session };

    std::unique_ptr<Publisher> publisher1{ new Publisher() };
    publisher1->name = "Eksmo";
    Wt::Dbo::ptr<Publisher> pPublisher1 = session.add(std::move(publisher1));

    std::unique_ptr<Publisher> publisher2{ new Publisher() };
    publisher2->name = "Willey";
    Wt::Dbo::ptr<Publisher> pPublisher2 = session.add(std::move(publisher2));


    std::unique_ptr<Book> book1{ new Book() };
    book1->title = "book1";
    book1->id_publisher = pPublisher1;
    Wt::Dbo::ptr<Book> pBook1 = session.add(std::move(book1));

    std::unique_ptr<Book> book2{ new Book() };
    book2->title = "book2";
    book2->id_publisher = pPublisher1;
    Wt::Dbo::ptr<Book> pBook2 = session.add(std::move(book2));

    std::unique_ptr<Book> book3{ new Book() };
    book3->title = "book1";
    book3->id_publisher = pPublisher2;
    Wt::Dbo::ptr<Book> pBook3 = session.add(std::move(book3));

    std::unique_ptr<Book> book4{ new Book() };
    book4->title = "book2";
    book4->id_publisher = pPublisher2;
    Wt::Dbo::ptr<Book> pBook4 = session.add(std::move(book4));


    std::unique_ptr<Shop> shop1{ new Shop() };
    shop1->name = "BooksWorld";
    Wt::Dbo::ptr<Shop> pShop1 = session.add(std::move(shop1));

    std::unique_ptr<Shop> shop2{ new Shop() };
    shop2->name = "BooksShop";
    Wt::Dbo::ptr<Shop> pShop2 = session.add(std::move(shop2));


    std::unique_ptr<Stock> stock1{ new Stock() };
    stock1->shops.insert(pShop1);
    stock1->shops.insert(pShop2);
    stock1->books.insert(pBook1);
    stock1->books.insert(pBook2);
    stock1->books.insert(pBook4);
    Wt::Dbo::ptr<Stock> pStock1 = session.add(std::move(stock1));

    std::unique_ptr<Stock> stock2{ new Stock() };
    stock2->shops.insert(pShop1);
    stock2->shops.insert(pShop2);
    stock2->books.insert(pBook1);
    stock2->books.insert(pBook3);
    stock2->books.insert(pBook4);
    Wt::Dbo::ptr<Stock> pStock2 = session.add(std::move(stock2));

    std::unique_ptr<Sale> sale1{ new Sale() };
    sale1->date_sale = 20250405;
    sale1->stock = pStock1;
    sale1->price = 2000;
    sale1->count = 10;
    Wt::Dbo::ptr<Sale> psale1 = session.add(std::move(sale1));

    std::unique_ptr<Sale> sale2{ new Sale() };
    sale2->date_sale = 20250412;
    sale2->stock = pStock2;
    sale2->price = 100;
    sale2->count = 2;
    Wt::Dbo::ptr<Sale> psale2 = session.add(std::move(sale2));

    transaction.commit();
}



void getPublisherInfo(Wt::Dbo::Session& session){
    std::string input;
    std::cout << "Введите имя или ID издателя: ";
    std::cin >> input;

    int publisherId = -1;
    try {
        publisherId = std::stoi(input);
    } catch (...) {}

    Wt::Dbo::ptr<Publisher> targetPublisher;

    if (publisherId != -1) {
        targetPublisher = session.find<Publisher>().where("id = ?").bind(publisherId);
    }
    else {
        targetPublisher = session.find<Publisher>().where("name = ?").bind(input);
    }

    if (!targetPublisher) {
        std::cerr << "Издатель не найден!" << std::endl;
        return;
    }

    auto books = session.query<Wt::Dbo::ptr<Book>>("SELECT b FROM book b WHERE b.id_publisher = ?")
                    .bind(targetPublisher.id());

    std::set<std::string> shopNames;

    for (const auto& book : books.resultList()) {
        // Получаем склады, где есть эта книга
        auto stocks = session.query<Wt::Dbo::ptr<Stock>>(
                        "SELECT s FROM book_stocks bs JOIN stock s ON bs.stock_id = s.id WHERE bs.book_id = ?")
                        .bind(book.id())
                        .resultList();

        for (const auto& stock : stocks) {
            // Получаем магазины, где есть этот склад
            auto shops = session.query<Wt::Dbo::ptr<Shop>>(
                        "SELECT s FROM shop s JOIN stock_shops ss ON ss.shop_id = s.id WHERE ss.stock_id = ?")
                        .bind(stock.id())
                        .resultList();

            for (const auto& shop : shops)
                shopNames.insert(shop->name);
        }
    }

    std::cout << "Магазины, где продаются книги издателя '" << targetPublisher->name << "':" << std::endl;
    for (const auto& name : shopNames)
        std::cout << "- " << name << std::endl;

}
