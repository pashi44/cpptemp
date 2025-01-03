#ifndef __ITERONEHPP__
#define __ITERONEHPP__

#include <iostream>

#include <list>
#include <chrono>
#include <thread>
#include <unistd.h>
#include <memory>
#include "ThreadOne.hpp"
using namespace threadone;
using namespace std;

namespace Iterone
{
    template <typename T>
    class IterOne

    {

    public:
        threadone::ThreadOne<T, S> obj;
    };
}

#endif