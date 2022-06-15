//
// Created by martin on 7.05.22 г..
//

#ifndef ACCOUNTMNGMNT_EXCHANGE_ORDERBOOK_H
#define ACCOUNTMNGMNT_EXCHANGE_ORDERBOOK_H

//#include "Order.h" // <string>
#include "Limit.h"
#include <map>
#include <unordered_map>
#include <vector>

namespace Exchange {
    class OrderBook {
    public:
        OrderBook();
        template<Side _side> void AddOrder(const Order& newOrder);
        template<Side _side> void CancelOrder(uint_fast64_t OldOrderID);
        template<Side _side> bool limitExists(uint_fast64_t limit);

        uint_fast64_t getBestSellPrice() const;
        uint_fast64_t getBestBuyPrice() const;


    private:
        // binary sorted tree for indexing bid and ask orders within order book
        // Limit contains all quotes in size>time order using another BST for that price level -> Not exactly but kinda
        // One Large problem we're facing is getting O(1) time sorted order
        std::map<uint_fast64_t, Limit> sellSideLimits; // For getting O(1) best sellPrice
        std::map<uint_fast64_t, Limit> buySideLimits; // For getting O(1) best buyPrice

        std::unordered_map<uint_fast64_t, std::map<uint_fast64_t, Limit>::iterator> sellSideIteratorsToLimits;
        std::unordered_map<uint_fast64_t, std::map<uint_fast64_t, Limit>::iterator> buySideIteratorsToLimits;

        std::unordered_map<uint_fast64_t, std::list<Order>::iterator> sellSideIteratorsToOrders; //<OrderId, PositionInRespectiveList>
        std::unordered_map<uint_fast64_t, std::list<Order>::iterator> buySideIteratorsToOrders; //<OrderId, PositionInRespectiveList>

        uint_fast64_t bestSellPrice;
        uint_fast64_t bestBuyPrice;

        std::vector<std::pair<Order, Order>> Executed;
    };
}

#endif //ACCOUNTMNGMNT_EXCHANGE_ORDERBOOK_H
