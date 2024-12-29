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
    try
    {

        std::thread t(threadFuncion);

        t.join();
    }
    catch (const std::runtime_error &e)

    {
        std::cerr << e.what() << std::endl;
    }
}
