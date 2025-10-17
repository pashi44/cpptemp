#ifndef __VECTORONE_HPP
#define __VECTORONE_HPP

#include <iostream>
#include <memory>
#include <vector>




using namespace std;

template <typename T, typename Alloc = std::allocator<T>, size_t size = 10>
class VectorOne
{
private:
    T obja;     
    T* oj;     
 

public:
    VectorOne() : obja{}, oj(nullptr) {}
VectorOne(const  T &&val) : obja(std::move(val)), oj(nullptr) { 








} 
    explicit VectorOne(const T& val) : obja(val), oj(nullptr) {}

    VectorOne(const VectorOne& other) : obja(other.obja), oj(nullptr) {}

    VectorOne(VectorOne&& other) noexcept : obja(std::move(other.obja)), oj(nullptr) {}



    
    VectorOne& operator=(const VectorOne& other)
    {
        if (this != &other)
            obja = other.obja;
        return *this;
    }

    VectorOne& operator=(VectorOne&& other) noexcept
    {
        if (this != &other)
            obja = std::move(other.obja);
        return *this;
    }

    VectorOne& getObject() { return *this; }

    T getObjectValue() const { return obja; }

    ~VectorOne() = default;

  public:

};

#endif
