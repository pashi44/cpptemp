#ifndef __THREADONEHPP__
#define __THREADONEHPP__
#include <iostream>
#include <thread>

template <typename T, typename S>
class ThreadOne
{
private:
    T &obj1;
    S &obj2;

public:
    ThreadOne(T &ob1, S &ob2) : obj1(ob1), obj2(ob2) // Proper initialization
    {

        cout
            << "Object created from threadFunction \n"
            << ((void *)&obj1) << '\t' << ((void *)&obj2)
            << endl;
        // cout
        // << ((void *)&ob1) << '\t' << ((void *)&ob2)
        // << endl;
    }

    void operator()() const
    {
        // cout << "obj1: " << obj1 << ", obj2: " << obj2 << endl;
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

    // shared_ptr<ThreadOne<T, S>> k = make_shared<ThreadOne<T, S>>(21, std::string("asdsads"));

    try
    {

        ThreadOne<T, S>
            m(obj1, obj2);           // Create ThreadOne object
        std::thread t1(std::ref(m)); // Pass ThreadOne object by reference
        t1.join();
        // Wait for thread to finish
        cout << "\n\n\n"
             << "*******************  frim **********"
             << "Thread finished execution  from  thread fucntion" << endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
