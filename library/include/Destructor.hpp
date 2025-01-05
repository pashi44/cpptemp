#ifndef WITHOUT_HPP
#define WITHOUT_HPP
#include <iostream>
#include <functional>

class Abst
{
public:
    Abst()
    {
        std::cout << "constructor invovked from abstarct class" << std::endl;
    };
    // virtual tables are handled by smart pointers

    ~Abst()
    {
        std::cout << "destructor invovked from abstarct class" << std::endl;
    };
    virtual void show() = 0;
};
class NonAbst
{
public:
    NonAbst()
    {
        std::cout << "constructor called from Non-Bastract  class" << std::endl;
    };
    // virtual tables are handled by smart pointers

    ~NonAbst()
    {
        std::cout << "Destructor called from Non-Bastract  class" << std::endl;
    };
};
template <typename T, typename S>
class Without : public Abst, public NonAbst
{
private:
    T getattr;
    std::function<S(void *)>   funcptr;

public:
    Without(const T &name,  const  std::function<S(void *)>  &funcptr );
    ~Without();
    T getAttributes() const;

void callfunction(void*);
    virtual void show() override;
};
// template classWithout<int, std::string>;
// template classWithout<std::string, void>;
template <typename T, typename S>
Without<T, S>::Without(const T &name, const std::function<S(void *)> &funcptrref)
{
    getattr = name;
    std::cout << "constructor initalised   from derrieved class:  \t" << getattr << std::endl;
funcptr =  (std::function<S(void*)>) funcptrref;
}
template <typename T, typename S>
Without<T, S>::~Without()
{

    
    std::cout << "destructor initalised   fro m derrieved class:  \t" << getattr << std::endl;
}
template <typename T, typename S>
T Without<T, S>::getAttributes() const
{
    return (*this).getattr;
}

template <typename T, typename S>

void Without<T, S>::show()

{

    std::cout << "overriden method from" << std::endl;
}
template <typename T, typename S>
void Without<T,S>::callfunction(void *param){
if(funcptr)
funcptr(nullptr);

}
void callablefunction(void *){

std::cout<< "called fucntion pointe  ffrom clas" <<std::endl;



}



#endif
