#ifndef __THREADSTHREATSHPP__
#define __THREADSTHREATSHPP__
#include <thread>
#include <iostream>
#include <mutex>
#include <memory>
using namespace std;
class DataWrapper
{
private:
    int a;
    string b;

public:
    void do_something();
};
class threadThreats
{
private:
    DataWrapper data;
    std::mutex mutexTwo;

public:
    template <typename Function>
    void Process_data(Function funObj)
    {
    }
};
DataWrapper *unpotected;
void malicious_function(DataWrapper &protected_data)
{
    unpotected = &protected_data;
}
#endif // !  __THREADSTHREATSHPP__
