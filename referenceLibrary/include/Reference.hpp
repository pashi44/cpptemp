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

    virtual ~Reference();
    // virtual void abstarctmethod() = 0;
    S getObject() const;
};

template class Reference<string>;
template class Reference<int>;

#endif // ! REFERENCEHPP
