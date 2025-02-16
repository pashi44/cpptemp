#include <string.h>
#include "threadplay.hpp"
#include <stdlib.h>
#include <sys/types.h>
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
    int makme = 1296;
    std::mutex mutexOne;
    std::vector<Iterone::IterOne<int, std::string>> IterplayVector;
    std::string name = "simon riely";

    using IterPair = Iterone::IterOne<int, std::string>; // Alias the Iter  class
    using Iter = std::vector<IterPair>::iterator;        //  alias the  iter  class into  vector class  and the iteratoe

    std::thread th1([&]()
                    {
     try
     {
         std::lock_guard<std::mutex> lock(mutexOne);
     
     IterplayVector.emplace_back(37, "SOAP Mac tavish");
     
     }
     
         catch (const std::exception &e)
                 {
             std::cerr << "Exception caught in thread: " << e.what() << std::endl;
         } });
    std::thread th2([&]()
                    {
     try
     {
         std::lock_guard<std::mutex> lock(mutexOne);
     
     IterplayVector.emplace_back(42, "cpatain price");
     
     }  
     
         catch (const std::exception &e1)
                 {
             std::cerr << "Exception caught in thread: " << e1.what() << std::endl;
         } });

    th1.join();
    th2.join();

    for (auto &iter : IterplayVector)
    {

        cout << iter.getStringObject() << endl;
    }

    return 0;
}