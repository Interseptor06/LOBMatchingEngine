//
// Created by martin on 7.05.22 г..
//

#include "OrderBook.h"

namespace Exchange {
    OrderBook::OrderBook() {
        bestSellPrice = 0;
        bestBuyPrice = 0;
    }

    template<>
    bool OrderBook::limitExists<Side::Buy>(uint_fast64_t limit) {
        return (buySideIteratorsToLimits.find(limit) == buySideIteratorsToLimits.end());
    }

    template<>
    bool OrderBook::limitExists<Side::Sell>(uint_fast64_t limit) {
        return (sellSideIteratorsToLimits.find(limit) == sellSideIteratorsToLimits.end());
    }

    template<>
    void OrderBook::AddOrder<Side::Sell>(const Order &newOrder) {
        if(limitExists<Side::Sell>(newOrder.getPrice())){
            auto it = sellSideLimits.emplace(newOrder.getPrice(), *(new Limit(newOrder.getPrice()))).first;
            auto limit = sellSideIteratorsToLimits.emplace(newOrder.getPrice(), it).first->second->second;
            // Next line both inserts order to limit_list but also inserts it in the sellSideIteratorsToOrders_HashMap
            sellSideIteratorsToOrders.emplace(newOrder.getId(), limit.addOrder(newOrder));
        }
        else{
            auto limit = sellSideIteratorsToLimits.find(newOrder.getPrice())->second->second;
            sellSideIteratorsToOrders.emplace(newOrder.getId(), limit.addOrder(newOrder));
        }
        bestSellPrice = sellSideLimits.begin()->first;
    }

    template<>
    void OrderBook::AddOrder<Side::Buy>(const Order &newOrder) {
        if(limitExists<Side::Buy>(newOrder.getPrice())){
            auto it = buySideLimits.emplace(newOrder.getPrice(), *(new Limit(newOrder.getPrice()))).first;
            auto limit = buySideIteratorsToLimits.emplace(newOrder.getPrice(), it).first->second->second;
            // Next line both inserts order to limit_list but also inserts it in the sellSideIteratorsToOrders_HashMap
            buySideIteratorsToOrders.emplace(newOrder.getId(), limit.addOrder(newOrder));
        }
        else{
            auto limit = buySideIteratorsToLimits.find(newOrder.getPrice());
            if(limit == buySideIteratorsToLimits.end()){
                throw std::runtime_error("You Dumb Fuck");
            }
            buySideIteratorsToOrders.emplace(newOrder.getId(), limit->second->second.addOrder(newOrder));
        }
        bestBuyPrice = buySideLimits.begin()->first;
    }

    template<>
    void OrderBook::CancelOrder<Side::Sell>(uint_fast64_t OldOrderID) {
        auto order = sellSideIteratorsToOrders.find(OldOrderID);
        if(order == sellSideIteratorsToOrders.end()){
            throw std::runtime_error("Order doesn't exist");
        }
        auto limit = sellSideIteratorsToLimits.find(order->second->getPrice())->second->second;
        limit.cancelOrder(order->second);
        bestSellPrice = sellSideLimits.begin()->first;
    }

    uint_fast64_t OrderBook::getBestSellPrice() const {
        return bestSellPrice;
    }

    uint_fast64_t OrderBook::getBestBuyPrice() const {
        return bestBuyPrice;
    }

    template<>
    void OrderBook::CancelOrder<Side::Buy>(uint_fast64_t OldOrderID) {
        auto order = buySideIteratorsToOrders.find(OldOrderID);
        if(order == buySideIteratorsToOrders.end()){
            throw std::runtime_error("Order doesn't exist");
        }
        // if order exists it isn't possible for the limit not to exist, which is why I don't check
        // whether buySideIteratorsToLimits->find() equals buySideIteratorsToLimits->end()
        auto limit = buySideIteratorsToLimits.find(order->second->getPrice())->second->second;
        limit.cancelOrder(order->second);
        bestBuyPrice = buySideLimits.begin()->first;
    }
}
