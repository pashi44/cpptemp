#include <iostream>
// #include "libOne.hpp"
#include <memory>

#include <string>
#include "PersonOne.hpp"
#include "Destructor.hpp"
using namespace std;

int main()

{
    // {
    // Abst *k = new Without<int, std::string>(27);
    // delete k;
    // }
    //
    // {
    //
    // NonAbst *nonAbsObject = new Without<int, void>(1296);
    //
    // delete nonAbsObject;    // }

    /* initlaise unwanted  class   constructors  and   may  cause mamory  overhreads

    better  to use smart  pointers


    */

    // usinque pointer delets when it does out of scope

    // std::unique_ptr<Without<int, void>> m(new Without<int, void>(1233));
    // or

    std::unique_ptr<Without<int, void>> m;
    m = make_unique<Without<int, void>>(1296);
    int recie = m->getAttributes();

    std::cout << recie << std::endl;
}
