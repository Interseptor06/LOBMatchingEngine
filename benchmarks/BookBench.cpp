//
// Created by martin on 7.05.22 г..
//

#include <benchmark/benchmark.h>
#include "../src/OrderBook.h"

static void BM_Buy(benchmark::State& state) {
    auto x = Exchange::Order{1, "GOOGL", 10012, 24, static_cast<bool>(Exchange::Side::Buy)};
    auto book = Exchange::OrderBook();
    for (auto _ : state) {
        // This code gets timed
            book.AddOrder<Exchange::Side::Buy>(x);
    }
}
static void BM_Sell(benchmark::State& state) {
    auto x = Exchange::Order{1, "GOOGL", 10012, 24, static_cast<bool>(Exchange::Side::Buy)};
    auto y = Exchange::Order{1, "GOOGL", 10012, 24, static_cast<bool>(Exchange::Side::Sell)};
    auto book = Exchange::OrderBook();
    for (auto _ : state) {
        // This code gets timed
            book.AddOrder<Exchange::Side::Sell>(x);
    }
}
static void BM_SellCancel(benchmark::State& state) {
    auto x = Exchange::Order{1, "GOOGL", 10012, 24, static_cast<bool>(Exchange::Side::Sell)};
    auto book = Exchange::OrderBook();
    book.AddOrder<Exchange::Side::Sell>(x);
    for (auto _ : state) {
        // This code gets timed
        book.AddOrder<Exchange::Side::Sell>(x);
        book.CancelOrder<Exchange::Side::Sell>(x.getId());
    }
}

// Register the function as a benchmark
BENCHMARK(BM_Buy);
BENCHMARK(BM_Sell);
//BENCHMARK(BM_SellCancel);
// Run the benchmark
BENCHMARK_MAIN();