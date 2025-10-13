    #include <iostream>
    // #include "libOne.hpp"
    #include <memory>
    #include <list>
    #include <string.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <sys/wait.h>
#include <mutex>
    #include "libOne.hpp"
    #include <thread>
    #include <chrono>
    #include  "VectorOne.hpp"
    #include <vector>

    using namespace std;
    int main(){
        pid_t pid;
        int makme = 1296;
        std::mutex mutexOne;
        std::string riley = "simon riely";

    vector<VectorOne<int>> vec = {
        VectorOne<int>(makme),
        VectorOne<int>(42),
        VectorOne<int>(),
        VectorOne<int>(99)
    };

    vec.resize(100); 
    vec.emplace_back(VectorOne<int>(777));

    cout << "Capacity: " << vec.capacity() << endl;

    for (size_t i = 0; i < 4; ++i)
        cout << vec[i].getObjectValue() << endl;

    return 0;
}
