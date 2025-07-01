#pragma once

#include <string>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>

class Publisher;
class Stock;

class Book {
public:
    // int id = 0;
    std::string title = "";
    Wt::Dbo::ptr<Publisher> publisher{};
    Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;

    template<class Action>
    void persist(Action& a){
        // Wt::Dbo::field(a, id, "id");
        Wt::Dbo::field(a, title, "title");
        Wt::Dbo::belongsTo(a, publisher, "publisher");
        Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "books");
    }
};