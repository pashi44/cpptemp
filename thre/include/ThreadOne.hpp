#ifndef __THREADONEHPP__
#define __THREADONEHPP__

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <thread>
#include <unistd.h>
template <typename T, class S>
class ThreadOne
{

public:
    void operator()() const {}

    ThreadOne()
    {
        cout << "thread had beeen called \n"
             << endl;
    }

    ~ThreadOne() {}
};
#endif // ! __THREADONEHPP__

struct __threadStruct
{
    void *funcpt = nullptr;
    uint8_t count;
    char *make = nullptr;
};

__threadStruct paramObj;
static void threadFuncion()
{
    ThreadOne<string, int> *k = new ThreadOne<string, int>();
    try
    {

        std::thread t1(*k);

        t1.join();
        cout

            << "thread waiting for the another   created " << endl;
    }

    catch (const std::runtime_error &k)
    {

        std::cerr << k.what() << std::endl;
    }
    delete k;

    k = nullptr;
}
