#include "libOne.hpp"
#include <iostream>
#include <string>
template <typename T, typename S>
LibOne<T, S>::LibOne(T age, S name)
{

    (*this).age = age;
    (*this).name = name;
}

template <typename T, typename S>
LibOne<T, S> LibOne<T, S>::getObject()
{
    return *this;
}

template <typename T, typename S>
S LibOne<T, S>::getName()
{
    return (*this).name;
}
