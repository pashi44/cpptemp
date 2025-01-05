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
    MoveSemantic() : obj1(), obj2() {}
    explicit MoveSemantic(const S &o1, const T &o2, std::string &&nams) noexcept : obj1(o1), obj2(std::move(nams))
    {
    }
    MoveSemantic(MoveSemantic &&other) noexcept : obj1(std::move(other.obj1)), obj2(std::move(other.obj2))
    {
        std::cout << "Move constructor called: Ownership transferred\n"
                  << endl;
        cout << other.obj1 << other.obj2 << endl;
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

//  cast name to rvalue reference with std:;move
// MoveSemantic<int, std::string> m(make, name, "ajskdbjas");
// MoveSemantic<int, std::string> obj2(std::move(m));
