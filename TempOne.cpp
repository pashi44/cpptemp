#include <iostream>
#include "libOne.hpp"
#include <string>
#include "PersonOne.hpp"

<<<<<<< HEAD
=======
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

>>>>>>> 7258b88 (usage o  critical sectional  fucntionality  withput RAII idom to use multiple  mutex unlocak statemets in try-catch  scopes)
using namespace std;
int main()
{
<<<<<<< HEAD
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

    basep.showDetails();
    std::cout
        << "objects are " << basep.getage()
        << std::endl;

    return 0;
}
=======

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
>>>>>>> 7258b88 (usage o  critical sectional  fucntionality  withput RAII idom to use multiple  mutex unlocak statemets in try-catch  scopes)
