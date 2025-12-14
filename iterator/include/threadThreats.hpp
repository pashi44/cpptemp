#ifndef __THREADSTHREATSHPP__
#define __THREADSTHREATSHPP__
#include <thread>
#include <iostream>
#include <mutex>
#include <memory>
#include <condition_variable>
#include <chrono>
#include <sys/types.h>

using namespace std;

class DataWrapper
{
private:
    int8_t a = 0;
    string b = "Datawrapper Default string";

public:
    void do_something()
    {
        cout << "from DataWrapper: a = " << a << ", b = " << b << endl;
    }
    void set_data(int A, const string &B)
    {
        a = A;
        b = B;
    }
};

class threadThreats
{
private:
    DataWrapper data;
    bool dataready = false;
    std::mutex classmutex;
    std::condition_variable cv;

public:
    // Notify when data is ready to be processed
    void
    produce_data(int newA, const string &newB)
    {
        {
            std::lock_guard<std::mutex> lock(classmutex);
            data.set_data(newA, newB);
            dataready = true;
        }
        cv.notify_one(); // Notify a waiting thread
    }
    // Wait until data is ready and then process it
    template <typename Function>
    void consume_data(Function funObj)
    {
        std::unique_lock<std::mutex> lock(classmutex);

        cv.wait(lock, [this]()
                { return dataready; }); // Wait until dataReady is true
        funObj(data);
        dataready = false; // Reset flag for next production
    }
};
void process_function(DataWrapper &protected_data)
{
    protected_data.do_something();
}
// threadThreats threadManager;
//
// Producer thread
//
// std::thread producer([&]()
//
//  {
//
// for (int i = 1; i <=  5; ++i) {
//
// threadManager.produce_data(i, "data_" + std::to_string(i));
//
// std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate work
//
// } });
//
// Consumer thread
//
// std::thread consumer([&]()
//
//  {
//
// for (int i = 1; i <= 5; ++i) {
//
// threadManager.consume_data(process_function);
//
// } });
//
// producer.join();
//
// consumer.join();

#endif // !  __THREADSTHREATSHPP__
