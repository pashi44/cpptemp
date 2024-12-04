#ifndef LIBONEHPP
#define LIBONEHPP
#include <iostream>
#include <string>
template <typename T, typename S>
class LibOne
{
private:
    S name;
    T age;

public:
    LibOne(T age, S name);

    LibOne<T, S> getObject();

    S getName();
};

// Explicit instantiation for the types used in the project
template class LibOne<int, std::string>;
template class LibOne<float, int>;
#endif // ! LIBONEH