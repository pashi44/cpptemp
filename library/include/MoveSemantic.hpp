#ifndef __MOVESEMANTICHPP__
#define __MOVESEMANTICHPP__
#include <iostream>
#include <memory>
#include <pthread.h>
using namespace std;
//  c98  standard for   types like struct, unions and class types  for primitive types
//  classt type dosent work ;  for backward compatibility  we use  class  type
template <typename S, typename T>
class MoveSemantic
{
private:
    S obj1;
    T obj2;

public:
    MoveSemantic() {}
    MoveSemantic(const S &o1, const T &o2, std::string &&nams) noexcept
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

    ~MoveSemantic()
    {
        cout << "destrcutor called \n"
             << endl;
    }
    MoveSemantic &getObj()
    {
        return (*this);
    }
};
#endif // __SHAREDPOINTH__
