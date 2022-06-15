//
// Created by martin on 14.06.22 г..
//

#ifndef ACCOUNTMNGMNT_EXCHANGE_MATCHINGENGINE_H
#define ACCOUNTMNGMNT_EXCHANGE_MATCHINGENGINE_H

#include "OrderBook.h"
#include <vector>

namespace Exchange {

    class MatchingEngine {
    public:
        MatchingEngine() = default;

        //template<Side _side> void AddOrder(const Order &newOrder);
        void AddOrder(const Order& newOrder);

        void CancelOrder(uint_fast64_t OldOrderID);

    private:
        void ProcessLimitOrderBook();
        std::vector<std::pair<Order, Order>> Executed;
        Exchange::OrderBook Book;
    };
}


#endif //ACCOUNTMNGMNT_EXCHANGE_MATCHINGENGINE_H
