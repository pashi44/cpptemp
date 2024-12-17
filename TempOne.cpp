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

    Reference<string> strObj = Reference<string>("this summer gonna hurt");
    cout << strObj.getObject();

    {

        unique_ptr<Reference<int>> k = make_unique<Reference<int>>(32);

        cout << k->getObject() << endl;
    }
}
