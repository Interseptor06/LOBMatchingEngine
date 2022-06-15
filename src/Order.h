//
// Created by martin on 7.05.22 г..
//

#ifndef ACCOUNTMNGMNT_EXCHANGE_ORDER_H
#define ACCOUNTMNGMNT_EXCHANGE_ORDER_H

#include <string>
#include <iostream>
#include <chrono>

namespace Exchange{
/**
 * Order Type
 * e.g. 70000001,Mal,73.21,100,100001,BUY
 * */
    enum class Side : bool{
        Buy = true,
        Sell = false
    };

    class Order {
    public:
        Order(int id, std::string name, int price, int quantity, bool isBuy) :
                m_id(id), m_price(price), m_quantity(quantity), // Next Line Gets Current Unix Time in Nanoseconds
                m_time(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count()),
                m_Side(static_cast<Side>(isBuy)), m_name(std::move(name)) {}

        // Getters for all the class members
        [[nodiscard]] unsigned int getId() const;
        [[nodiscard]] unsigned int getPrice() const;
        [[nodiscard]] unsigned int getQuantity() const;
        [[nodiscard]] unsigned long getTime() const;
        [[nodiscard]] Exchange::Side getSide() const;
        [[nodiscard]] const std::string &getName() const;

    private:
        unsigned int m_id;
        unsigned int m_price; // in cents
        unsigned int m_quantity;
        unsigned long m_time;
        Side m_Side;
        std::string m_name;
    };
    std::ostream &operator<<(std::ostream &out, const Order &order);
    std::ostream &operator<<(std::ostream &out, const Side &side);
    bool operator==(const Order &lhs, const Order &rhs);
    bool operator!=(const Order &lhs, const Order &rhs);
}

#endif ////ACCOUNTMNGMNT_EXCHANGE_ORDER_H