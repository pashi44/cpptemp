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

using namespace std;
std::thread t(threadFuncion);

int main()

{
    t.join();
}
