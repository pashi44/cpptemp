#pragma once

#include <chrono>
#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <memory>
#include <condition_variable>
#include <thread>
#include <queue>
#include <list>

using namespace std;

template <typename T>
class CondVra
{
public:
    std::condition_variable cvone;
    int sharedvariable;
    std::mutex concvarMutex;
    bool condpredicate;
    T obj1; // Changed from reference to value //cant be push when use d
    // data structure of type  T

    CondVra(const T &ob1 = T()) : sharedvariable(0),
                                  condpredicate(false),
                                  obj1(ob1) {}

    CondVra(const CondVra &cv) = delete;
};

// std::queue<std::shared_ptr<CondVra<S>>> crvqueu;
// auto cvObject = std::make_shared<CondVra<S>>("pashi"); // Create initial object
//
// std::thread threadone([&crvqueu, &cvObject]()
//   {
// while (makme !=  1300) {
// {
// std::unique_lock<std::mutex> lk(cvObject->concvarMutex);
// cvObject->obj1 = "pashi" + std::to_string(makme);
// crvqueu.push(cvObject);
// ++makme;
// std::cout << "pushed\t" <<   crvqueu.front()->obj1 << std::endl;
// }
//
// std::this_thread::sleep_for(std::chrono::seconds(1));
// cvObject->cvone.notify_one();
// } });
//
// std::thread threadtwo([&crvqueu, &cvObject]() { // Add cvObject to capture
// while (true)
// {
// std::unique_lock<std::mutex> lock(cvObject->concvarMutex);
//
// Wait until notified and queue is not empty // not ot waste the cycles
// cvObject->cvone.wait(lock, [&crvqueu, &cvObject]()
//  { return !cvObject->condpredicate; });
//
// could have use the iterator to get object,
// but i spent too much time on this
// auto item = crvqueu.front();
// crvqueu.pop();
// std::cout << "consumed: " << item->obj1 << std::endl;
//
