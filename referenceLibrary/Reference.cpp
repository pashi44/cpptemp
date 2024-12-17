#include "Reference.hpp"

template <typename S>
Reference<S>::Reference(const S &obj)
{

    objtype = obj;
}

template <typename S>
S Reference<S>::getObject() const
{

    return objtype;
}

template <typename S>
Reference<S>::~Reference()
{

    cout << "destructor called\n"
         << endl;
}