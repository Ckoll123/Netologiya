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

        session.createTables();

        // fillTables(session);

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