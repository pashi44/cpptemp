#include <string.h>
#include "threadplay.hpp"
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <vector>
#include <thread>
#include <stdexcept>
#include <iostream>
#include <cassert>
#include "IterOne.hpp"
using namespace std;
using namespace Iterone;
using namespace threadone;
using namespace threadplay;
int main()
{

IterOne<string, nullptr_t> iterobj{std::string("TestString"), nullptr};

auto   * iterpointer  =  &iterobj;


iterobj(std::string("prashanthn  redd y"),   nullptr);







 iterpointer=  nullptr;


return 0;

}