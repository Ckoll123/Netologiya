#pragma once

#include <string>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>

class Book;

class Publisher {
public:
    // int id = 0;
    std::string name = "";
    Wt::Dbo::collection< Wt::Dbo::ptr<Book> > books;

    template<class Action>
    void persist(Action& a)
    {
        // Wt::Dbo::field(a, id, "id");
        Wt::Dbo::field(a, name, "name");
        Wt::Dbo::hasMany(a, books, Wt::Dbo::ManyToOne, "id_publisher");
    }
};