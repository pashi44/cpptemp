#include <iostream>
// #include "libOne.hpp"
#include <memory>
#include <list>
#include <string.h>
#include "PersonOne.hpp"
#include "Reference.hpp"
#include <MoveSemantic.hpp>

// #include "Destructor.hpp"
#include "ThreadOne.hpp"
#include <stdlib.h>
#include <sys/types.h>
#include <vector>
#include <thread>
#include <stdexcept>
#include <iostream>
using namespace std;

int main()
{
    int make = 156;
    std::string name = "pashiasdlksd";

    try
    {
        std::thread t(threadFunction<int, std::string>, std::ref(make), std::ref(name));
        t.join();
        cout << "From main thread: " << ((void *)&make) << "\t" << ((void *)&name) << "\n\n"
             << endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
