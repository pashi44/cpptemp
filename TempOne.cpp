#include <iostream>
// #include "libOne.hpp"
#include <memory>
#include <list>
#include <string.h>
// #include "PersonOne.hpp"
// #include "Reference.hpp"
// #include <MoveSemantic.hpp>
#include "threadplay.hpp"

// #include "Destructor.hpp"
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <vector>
#include <thread>
#include <stdexcept>
#include <iostream>
#include <cassert>
#include "IterOne.hpp"

using namespace std;
using namespace threadone;
using namespace threadplay;
int main()
{

    pid_t pid;
    int makme = 1296;
    std::mutex mutexOne;
    std::string name = "simon riely";
    std::thread th([&]()
                   {
        try
        {
            mutexOne.lock();
            std::cout << "Thread is executing. Protecting shared resources.\n";
            std::cout << "Shared data: " << makme << ", " << name << std::endl;
            if (makme   < 20)
            {
                throw std::runtime_error("An  assertion error occurred!");
            }
            mutexOne.unlock(); //  a deadlock
        }
        catch (const std::exception &e)
        {
            mutexOne.unlock(); // Ensure the mutex is unlocked in case of an exception
            std::cerr << "Exception caught in thread: " << e.what() << std::endl;
        } });

    th.join();
    return 0;
}