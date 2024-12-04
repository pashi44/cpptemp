#include <iostream>
#include "libOne.hpp"
#include <string>
#include "PersonOne.hpp"

using namespace std;
int main()
{
    //
    // LibOne<int, std::string> m = LibOne<int, std::string>(28, "prashanth");
    // std::cout << "age is " << m.getName() << std::endl;
    //
    // LibOne<float, int> k = LibOne<float, int>(22.3, 256);
    // std::cout << "age is " << k.getName() << std::endl;
    //

    BasePerson<int, std::string, std::string> basep = BasePerson<int, std::string, std::string>(
        29, "prashanth", "programmer"

    );

    return 0;
}
