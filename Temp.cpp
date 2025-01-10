#include <iostream>
#include "libOne.hpp"
#include <string>
#include "PersonOne.hpp"
#include <stdlib.h>
#include <sys/types.h>
#include "async.hpp"
#include <chrono>
#include <unistd.h>
using namespace std;
pid_t pid;
int makme = 1296;
auto mainThreadID = std::this_thread::get_id();
using S = std::string;
int main()
{
    std::promise<int> prom;

    std::future<int> fut = prom.get_future();

    std::thread threadone([&prom]()
                          {
                              std::this_thread::sleep_for(std::chrono::seconds(5));
                              prom.set_value(makme  + 10); });
    std::cout << "Waiting for the value to be set\n";
    auto value = fut.get();
    std::cout << "Value set: " << value << '\n';
    threadone.join();
    return 0;
}
