#ifndef __THREADONEHPP__
#define __THREADONEHPP__

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
template <typename T, class S>
class ThreadOne
{
    ThreadOne() = default;
};
#endif // ! __THREADONEHPP__

struct __threadStruct
{
    void *funcpt = nullptr;
    uint8_t count;
    char *make = nullptr;
};

void threadFuncion()
{
    __threadStruct paramObj;
    paramObj.make = (char *)malloc(sizeof(char) * 10);

    strcpy(paramObj.make, "structtype");
    std::cout
        << paramObj.make << std::endl;

    free(paramObj.make);

    paramObj.make = nullptr;
}
