#include <iostream>
// #include "libOne.hpp"
#include <memory>

#include <string>
#include "PersonOne.hpp"
#include "Reference.hpp"
#include "Destructor.hpp"
using namespace std;

int main()

{
    //
    // {
    // std::unique_ptr<Without<int, void>> m;
    // m = make_unique<Without<int, void>>(1296, callablefunction);
    // int recie = m->getAttributes();
    // m->callfunction(nullptr);
    // }

    // Reference<string> strObj = Reference<string>("this summer gonna hurt");

    {

        Reference<int> k = Reference<int>(1296);
        Reference<int> copy(k);
        std::cout << *(copy.name) << std::endl;
        std::cout << *k.name << std::endl;
    }
}
