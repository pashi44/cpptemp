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
};
