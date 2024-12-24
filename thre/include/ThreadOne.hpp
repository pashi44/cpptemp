#ifndef __THREADONEHPP__
#define __THREADONEHPP__
#include <iostream>
#include <memory>
#include <pthread.h>
using namespace std;
//  c98  standard for   types like struct, unions and class types  for primitive types
//  classt type dosent work ;  for backward compatibility  we use  class  type
template <typename S, typename T>
class ThreadOne
{
private:
    S obj1;
    T obj2;

public:
    ThreadOne() {}
    ThreadOne(const S &o1, const T &o2, std::string &&nams) noexcept
    {

        obj1 = o1;

        obj2 = o2;

        nams = std::move(obj2);
        cout << "the valye of  obj2 is\t  "
             << obj2
             << "\t  after modification"
             << endl;

        cout << "the valye of   nams  is\t  " << nams << "\t  after modification" << endl;
    }

    ~ThreadOne()
    {
        cout << "destrcutor called \n"
             << endl;
    }
    ThreadOne &getObj()
    {
        return (*this);
    }
};
#endif // __SHAREDPOINTH__
