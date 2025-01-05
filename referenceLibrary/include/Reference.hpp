#ifndef REFERENCEHPP
#define REFERENCEHPP

#include <iostream>
#include <stdio.h>
#include <pthread.h>
using namespace std;

template <typename S>

class Reference

{
private:
    S objtype;

public:
    Reference(const S &obj);
    Reference(const Reference<S> &a);
    virtual ~Reference();

    S *name;

    // virtual void abstarctmethod() = 0;
    Reference<S> &
    getObject();
};

template class Reference<string>;
template class Reference<int>;

#endif // ! REFERENCEHPP
