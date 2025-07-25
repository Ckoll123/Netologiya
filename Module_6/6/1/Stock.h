#pragma once

#include <string>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>

class Book;
class Shop;
class Sale;

class Stock {
public:
    // int id = 0;
    int count = 0;
    Wt::Dbo::ptr<Book> books;
    Wt::Dbo::ptr<Shop> shops;
    Wt::Dbo::collection< Wt::Dbo::ptr<Sale> > sales;

    template<class Action>
    void persist(Action& a){
        // Wt::Dbo::field(a, id, "id");
        Wt::Dbo::field(a, count, "count");
        Wt::Dbo::belongsTo(a, books, "books");
        Wt::Dbo::belongsTo(a, shops, "shops");
        Wt::Dbo::hasMany(a, sales, Wt::Dbo::ManyToOne, "id_stock");
    }
};