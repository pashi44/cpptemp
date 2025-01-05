#ifndef __THREADPLAYHPP__
#define __THREADPLAYHPP__
#include <list>
#include <exception>
#include <cassert>
#include <vector>
#include <thread>
#include <iostream>

#include "ThreadOne.hpp"

using namespace std;
using namespace threadone;

class AbstarctClass
{
public:
    virtual void getnothing() = 0;
    virtual ~AbstarctClass() = default;
};

namespace threadplay
{

    template <typename T, typename S>
    class Threadplay : public AbstarctClass
    {

    public:
        T obj1; //  passing refe ffrom the caller
        S obj2;

    public:
        Threadplay(T &ob1, S &ob2) : obj1(ob1), obj2(ob2) {}
        Threadplay(T &&ob1, S &&ob2) : obj1(ob1), obj2(ob2)
        {
            std::cout << "Addresses: obj1: " << (void *)&ob1 << ", obj2: " << (void *)&ob2 << '\n';
        }

        std::string &
        returnS()
        {
            obj2 = std::string("ashdjfasjhdvahsjd");

            return (*this).obj2;
        }

        ~Threadplay()
        {
            cout << "dcalss  called\n"
                 << endl;
        }
        void getnothing() override
        {

            cout << "from dclass\n"
                 << endl;
        }
    };
}

#endif