 /* Created by martin on 14.05.22 г...
 * This cpp file tests the interfaces provided buy the Limit.h, Order.h, OrderBook.h
 */
#include "../src/OrderBook.h" // Order.h, Limit.h
 bool testOrderInterface() {
     Exchange::Order testObj(1, "APPLE", 2404, 10, true);
     try {
         testObj.getId();
         testObj.getSide();
         testObj.getTime();
         testObj.getQuantity();
         testObj.getPrice();
         testObj.getName();
     }
     catch (std::exception &e) {
         return false;
     }
     return true;
 }

 void testLimitAdd(){
     Exchange::Order testObj(1, "APPLE", 2404, 10, true);
     Exchange::Limit testLim(testObj.getPrice());
     auto y = testLim.addOrder(testObj);
 }

 void testLimitDelete(){
     Exchange::Order testObj(1, "APPLE", 2404, 10, true);
     Exchange::Limit testLim(testObj.getPrice());
     auto y = testLim.addOrder(testObj);
     testLim.cancelOrder(y);
 }
 void testLimitPrice_Volume(){
     Exchange::Order testObj(1, "APPLE", 2404, 10, true);
     Exchange::Limit testLim(testObj.getPrice());
     auto y = testLim.addOrder(testObj);
     testLim.getVolume();
     testLim.getLimitPrice();
 }