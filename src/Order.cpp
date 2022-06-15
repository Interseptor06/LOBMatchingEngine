//
// Created by martin on 8.05.22 г..
//

#include "Order.h"

namespace Exchange{

    std::ostream &operator<<(std::ostream &out, const Side &side) {
        if(side == Side::Buy){
            out << "Buy";
        }
        else {
            out << "Sell";
        }
        return out;
    }


    std::ostream &operator<<(std::ostream &out, const Order &order) {
            out << order.getName() << "_" << order.getPrice() << "_" << order.getQuantity() <<
                "_" << order.getTime() << "_" << order.getSide();
        return out;
    }


    bool operator==(const Order &lhs, const Order &rhs) {
        return lhs.getId() == rhs.getId() &&
               lhs.getName() == rhs.getName() &&
               lhs.getPrice() == rhs.getPrice() &&
               lhs.getQuantity() == rhs.getQuantity() &&
               lhs.getTime() == rhs.getTime() &&
               lhs.getSide() == rhs.getSide();
    }


    bool operator!=(const Order &lhs, const Order &rhs) {
        return !(lhs == rhs);
    }

    unsigned int Order::getId() const {
        return m_id;
    }

    unsigned int Order::getPrice() const {
        return m_price;
    }
    unsigned int Order::getQuantity() const {
        return m_quantity;
    }
    unsigned long Order::getTime() const {
        return m_time;
    }
    Side Order::getSide() const {
        return m_Side;
    }
    const std::string &Order::getName() const {
        return m_name;
    }
}