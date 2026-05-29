<<<<<<< HEAD
<<<<<<< HEAD
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
=======
#include <vector>
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include  "libOne.hpp"

#include <chrono>

using namespace std;

// Shared resources
std::mutex mutexone;
std::condition_variable condvar;
atomic<bool> flag{false};
vector<int> shredlisr;

// Producer lambda
// auto producer = [](int a) {
//     {
//         std::unique_lock<mutex> lock(mutexone);
//         shredlisr.push_back(a * 10);  // Push the value 'a * 10' into the shared vector
//         cout << "Produced by thread: " << a << "\tValue: " << shredlisr.back() << endl;
//     }
//     this_thread::sleep_for(chrono::seconds(1));  // Simulate work
// };

// // Consumer lambda
// auto consumer = []() {
//     while (true) {
//         std::unique_lock<mutex> lock(mutexone);
//         condvar.wait(lock, []() { return !shredlisr.empty() || flag.load(); });  // Wait for items or flag

//         if (shredlisr.empty() && flag.load()) {
    //         }

//         if (!shredlisr.empty()) {
//             int value = shredlisr.back();  // Consume the last element
//             shredlisr.pop_back();
    //             break;  // Exit if no more items and flag is set
//             cout << "Consumed by thread: " << value << endl;
//         }
//     }
// };


// 
int main() {



    staticAssert  k =  staticAssert();


std::cout << k.sharedstatic<< std::endl;

LibOne<int, std::string> linone=   LibOne<int , std::string>(456, std::string("pradhanwj"));

linone.sharedstatic =  67;

std::cout << k.sharedstatic<< std::endl;


return 0;
>>>>>>> dev

}
<<<<<<< HEAD
=======
#include <vector>
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include  "libOne.hpp"

#include <chrono>

using namespace std;

// Shared resources
std::mutex mutexone;
std::condition_variable condvar;
atomic<bool> flag{false};
vector<int> shredlisr;

// Producer lambda
// auto producer = [](int a) {
//     {
//         std::unique_lock<mutex> lock(mutexone);
//         shredlisr.push_back(a * 10);  // Push the value 'a * 10' into the shared vector
//         cout << "Produced by thread: " << a << "\tValue: " << shredlisr.back() << endl;
//     }
//     this_thread::sleep_for(chrono::seconds(1));  // Simulate work
// };

// // Consumer lambda
// auto consumer = []() {
//     while (true) {
//         std::unique_lock<mutex> lock(mutexone);
//         condvar.wait(lock, []() { return !shredlisr.empty() || flag.load(); });  // Wait for items or flag

//         if (shredlisr.empty() && flag.load()) {
    //         }

//         if (!shredlisr.empty()) {
//             int value = shredlisr.back();  // Consume the last element
//             shredlisr.pop_back();
    //             break;  // Exit if no more items and flag is set
//             cout << "Consumed by thread: " << value << endl;
//         }
//     }
// };


// 
int main() {



    staticAssert  k =  staticAssert();


std::cout << k.sharedstatic<< std::endl;

LibOne<int, std::string> linone=   LibOne<int , std::string>(456, std::string("pradhanwj"));

linone.sharedstatic =  67;

std::cout << k.sharedstatic<< std::endl;


return 0;

}
// 
>>>>>>> origin/dev
=======
// 
>>>>>>> dev
