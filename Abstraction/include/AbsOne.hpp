#pragma once

#include <iostream>
#include <utility>
#include <string>

namespace Abstration {

template <typename T, size_t N>
class AbsOne {
protected:
    T value;

public:
    AbsOne() = default;

    // Move constructor
    AbsOne(T&& k) : value(k) {
        std::cout << "AbsOne move constructor: " << value << std::endl;
        std::cout << "Address of moved-from value: " << static_cast<const void*>(&k) << std::endl;

this->value  +=  "is a   good code ";


    }

    // Copy constructor (optional)
    AbsOne(const T& k) : value(k) {
        std::cout << "AbsOne copy constructor: " << value << std::endl;
    }

    virtual void showClassType() {
        std::cout << "Called AbsOne::showClassType()" << std::endl;
    }

    virtual void buildType() {}

    T getValue() const {
        return this->value;
    }

    virtual ~AbsOne() {
        std::cout << "AbsOne destructor: value = " << value << std::endl;
    }
};

template <typename S, size_t N>
class AbsTwo : public AbsOne<S, N> {
public:
    // Move constructor with forward is use dwhen  we ant to  preserve the 
    //l/r values to  base class  handing out the ownership  
    // if not we could have  copy initalized in the constructore of abse class
    
    AbsTwo(S&& k) : AbsOne<S, N>(std::forward<S>(k)) {
        std::cout << "AbsTwo move constructor\n";
    }

    // Copy constructor (optional)
    AbsTwo(const S& k) : AbsOne<S, N>(k) {
        std::cout << "AbsTwo copy constructor\n";
    }

    void showClassType() override {
        std::cout << "Called AbsTwo::showClassType()" << std::endl;
    }

    void buildType() override {


        
    }

    virtual ~AbsTwo() {
        std::cout << "AbsTwo destructor\n";
    }
};



  template  <typename S , size_t K>
  class  AbsThree  : public  AbsOne<S, 0>{

private:
S membervariable;

public:
AbsThree(S&& obj)  : AbsOne<S,K>(std::forward<S>(obj)){}

 void showClassType() override {
        std::cout << "Called AbsThree::showClassType()" << std::endl;
    }

    void buildType() override {

        std::cout << "Called AbsThree::buildType()" << std::endl;


    }

void GetNothing(){
        std::cout << "Called AbsThree::GetNothing()" << std::endl;


        std::cout << this->value <<std::endl;

}


~AbsThree
(){}





  };



// Explicit template instantiations (optional)
template class AbsOne<std::string, 0>;
template class AbsTwo<std::string, 0>;
template class AbsThree<std::string, 0>;

}  // namespace Abstration
