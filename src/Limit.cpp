//
// Created by martin on 8.05.22 г..
//

#include "Limit.h"

namespace Exchange{
    std::list<Order>::iterator Limit::addOrder(const Order &newOrder) {
        Orders.push_back(newOrder);
        return Orders.end().operator--();
    }

    void Limit::cancelOrder(std::list<Order>::const_iterator delOrder) {
        Orders.erase(delOrder);
    }

    unsigned int Limit::getLimitPrice() const {
        return limitPrice;
    }

    unsigned int Limit::getVolume() const {
        return Orders.size();
    }

    std::ostream &operator<<(std::ostream &out, const Limit &limit) {
        out << "[ " << limit.getLimitPrice() << ", <";
        for (const auto& node: limit.getOrders())
            std::cout << node << ",";
        out << "> ]";
        return out;
    }

    const std::list<Order> &Limit::getOrders() const {
        return Orders;
    }
}