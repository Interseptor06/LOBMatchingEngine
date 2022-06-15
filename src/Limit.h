//
// Created by martin on 7.05.22 г..
//

#ifndef ACCOUNTMNGMNT_EXCHANGE_LIMIT_H
#define ACCOUNTMNGMNT_EXCHANGE_LIMIT_H

#include <list>
#include "Order.h"

namespace Exchange {

    struct [[maybe_unused]] OrderSizeTimeComparator {
        bool operator()(const Order *rhs, const Order *lhs) const {
            unsigned int qty_rhs = rhs->getQuantity(), qty_lhs = lhs->getQuantity();
            if (qty_rhs != qty_lhs)
                return qty_rhs > qty_lhs;
            else
                return rhs->getTime() < lhs->getTime();
        }
    };

    class Limit {
    public:
        explicit Limit(unsigned int _limitPrice){
            limitPrice = _limitPrice;
        }

        std::list<Order>::iterator addOrder(const Order &newOrder);
        void cancelOrder(std::list<Order>::const_iterator delOrder);
        [[nodiscard]] unsigned int getLimitPrice() const;
        [[nodiscard]] unsigned int getVolume() const;
        [[nodiscard]] const std::list<Order> &getOrders() const;

    private:
        unsigned int limitPrice;
        std::list<Order> Orders;
    };
    std::ostream &operator<<(std::ostream &out, const Limit &limit);
}

#endif //ACCOUNTMNGMNT_EXCHANGE_LIMIT_H
