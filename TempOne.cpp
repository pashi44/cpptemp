#include <iostream>
#include "libOne.hpp"
#include <string>
#include "PersonOne.hpp"

// #include "Destructor.hpp"
#include <stdlib.h>
#include <sys/types.h>

#include <chrono>
#include <unistd.h>
// #include "IterOne.hpp"
#include "threadThreats.hpp"
using namespace std;
pid_t pid;
int makme = 1296;
// std::queue<threadThreats> shared_dataqueue;

auto mainThreadID = std::this_thread::get_id();

int main()
{

    threadThreats threadManager;

    // Producer thread
    std::thread producer([&]()
                         {
        for (int i = 1; i <= 5; ++i) {
            threadManager.produce_data(i, "data_" + std::to_string(i));
            std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate work
        } });

    // Consumer thread
    std::thread consumer([&]()
                         {
        for (int i = 1; i <= 5; ++i) {
            threadManager.consume_data(process_function);
        } });

    producer.join();
    consumer.join();

    return 0;
}
