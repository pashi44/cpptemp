#include "Reference.hpp"

template <typename S>
Reference<S>::Reference(const S &obj)
{

    objtype = obj;

    name = new S(obj);
}

template <typename S>
Reference<S> &Reference<S>::getObject()
{
    // returns the refernce to current instance of refernce o=bject  rather than copying
    return (*this);
}

template <typename S>
Reference<S>::~Reference()
{
    delete name;
    cout
        << "destructor called\n"
        << endl;
}

template <typename S>
Reference<S>::Reference(const Reference<S> &a)

{

    objtype = a.objtype;

    if (a.name)
    {
        name = new S(*a.name);
    }
    else
    {
        name = nullptr;
    }
}
