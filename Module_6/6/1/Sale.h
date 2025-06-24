#pragma once

#include <string>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>

class Stock;

class Sale {
public:
    // int id = 0;
    float price = 0;
    int date_sale = 0;
    Wt::Dbo::ptr<Stock> stock;
    int count = 0;

    template<class Action>
    void persist(Action& a)
    {
        // Wt::Dbo::field(a, id, "id");
        Wt::Dbo::field(a, price, "price");
        Wt::Dbo::field(a, date_sale, "date_sale");
        Wt::Dbo::belongsTo(a, stock, "id_stock");
        Wt::Dbo::field(a, count, "count");
    }
};