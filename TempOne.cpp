#include <iostream>
#include "libOne.hpp"
#include <string>
#include "PersonOne.hpp"

// #include "Destructor.hpp"
#include <stdlib.h>
#include <sys/types.h>

#include <chrono>
#include <unistd.h>
// #include "IterOne.hpp"
// #include "threadThreats.hpp"
#include "CondVar.hpp"

using namespace std;
pid_t pid;
int makme = 1296;

auto mainThreadID = std::this_thread::get_id();

using S = std::string;

int main()
{
    std::queue<std::shared_ptr<CondVra<S>>> crvqueu;
    auto cvObject = std::make_shared<CondVra<S>>("pashi"); // Create initial object

    std::thread threadone([&crvqueu, &cvObject]()
                          {
        while (makme !=  1300) {
            {
                std::unique_lock<std::mutex> lk(cvObject->concvarMutex);
                cvObject->obj1 = "pashi" + std::to_string(makme);
                crvqueu.push(cvObject);
                ++makme;
                std::cout << "pushed\t" <<   crvqueu.front()->obj1 << std::endl;
            }

            std::this_thread::sleep_for(std::chrono::seconds(1));
            cvObject->cvone.notify_one();
        } });

    std::thread threadtwo([&crvqueu, &cvObject]() { // Add cvObject to capture
        while (true)
        {
            std::unique_lock<std::mutex> lock(cvObject->concvarMutex);

            // Wait until notified and queue is not empty// not ot waste the cycles
            cvObject->cvone.wait(lock, [&crvqueu, &cvObject]()
                                 { return !cvObject->condpredicate; });

            // could have use the iterator to  get object  ,  but i spent  too much time on this
            auto item = crvqueu.front();
            crvqueu.pop();
            std::cout << "consumed: " << item->obj1 << std::endl;

            // Lock is automatically released when going out of scope
        }
    });
    threadone.join();
    threadtwo.join();

    return 0;
}
