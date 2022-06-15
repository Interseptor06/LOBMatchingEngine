cmake_minimum_required(VERSION 3.21)
project(AccountMngmnt_Exchange)

set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "-Ofast -pthread")

add_executable(AccountMngmnt_Exchange BookBench.cpp  ../src/Order.h ../src/Limit.h ../src/OrderBook.cpp ../src/OrderBook.h ../src/Limit.cpp ../src/Order.cpp)

find_package(benchmark REQUIRED)
target_link_libraries(AccountMngmnt_Exchange benchmark::benchmark)


