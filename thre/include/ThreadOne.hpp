#ifndef __THREADONEHPP__
#define __THREADONEHPP__
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <thread>
#include <unistd.h>
template <typename T, typename S>
class ThreadOne
{
private:
    T obj1;
    S obj2;

public:
    ThreadOne(T &ob1, S &ob2)
    {
        obj1 = ob1;
        obj2 = ob2;
        cout << "Object created from  theradFucntion \n"
             << endl;
    };
    void
    operator()() const
    {
        cout << ((void *)&obj1) << "\t" << ((void *)&obj2) << endl;
    }

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
template <typename T, typename S>
void threadFunction(T &obj1, S &obj2)
{
    ThreadOne<T, S> m(obj1, obj2);
    try
    {
        std::thread t1(std::ref(m));
        t1.join();
        cout
            << "thread waiting for the another   created " << endl;
    }
    catch (const std::runtime_error &k)
    {
        std::cerr << k.what() << std::endl;
    }
}
