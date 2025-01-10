#ifndef __ITERONEHPP__
#define __ITERONEHPP__
#include <iostream>
#include <list>
#include <chrono>
#include <thread>
#include <iterator>
#include <vector>
#include <memory>
#include "ThreadOne.hpp"
using namespace threadone;
using namespace std;
namespace Iterone
{
    template <typename T, typename S>
    class IterOne
    {
    private:
        T obj1;
        S obj2;

    public:
        IterOne(const T &ob1, const S &ob2) : obj1(ob1), obj2(ob2)
        {
        }

        void operator()(T &ob1, S &ob2)
        {
            obj1 = ob1;
            obj2 = ob2;
        }

        ~IterOne() {}
    };
}
#endif
