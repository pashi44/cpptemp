#ifndef WITHOUT_HPP
#define WITHOUT_HPP

#include <iostream>
template <typename T, typename S>
class Without
{

private:
    T getattr;

public:
    Without(const T &name);
    ~Without();

    T getAttributes() const;
};

template <typename T, typename S>
Without<T, S>::Without(const T &name)
{
    getattr = name;
}

template <typename T, typename S>

Without<T, S>::~Without()
{
}

template <typename T, typename S>
T Without<T, S>::getAttributes() const
{

    return (*this).getattr;
}

#endif
