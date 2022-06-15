//
// Created by martin on 14.06.22 г..
//

#include "MatchingEngine.h"

namespace Exchange{

    void MatchingEngine::AddOrder(const Order &newOrder) {
        long QuantityRemaining = newOrder.getQuantity();
        Exchange::Side Side = newOrder.getSide();
        while(){

        }
    }


    // TODO: Add a way to figure out whether an order is BuySide or SellSide using OldOrderID
    void MatchingEngine::CancelOrder(uint_fast64_t OldOrderID) {
        Book
        .CancelOrder<Side::Buy>(OldOrderID);
        Book.CancelOrder<Side::Sell>(OldOrderID);
    }

    void MatchingEngine::ProcessLimitOrderBook(){

    }
}
