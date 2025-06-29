#include <iostream>
// #include "libOne.hpp"
#include <memory>
#include <list>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#include  "AbsOne.hpp"


#include <chrono>

#include <vector>
#include <thread>
#include <stdexcept>
#include <iostream>
#include <cassert>
#include "IterOne.hpp"

using namespace std;
using namespace threadone;
using namespace Abstration;


int main()
{

    pid_t pid;
    int makme = 1296;
    std::mutex mutexOne;
    std::string riley = "simon riely";


int  value=23;
// std::cout << "Address in main: " << static_cast<const void*>(&value) << std::endl;
// 



AbsOne<std::string,0>  *oneplayer =
 new AbsThree<std::string, 0>(std::move(std::string("pashi")));


 
 
 AbsThree<std::string, 0>   *castedpointer=dynamic_cast<AbsThree<std::string, 0>*> (oneplayer);


if(castedpointer ==nullptr)castedpointer->GetNothing();







    return 0;
}