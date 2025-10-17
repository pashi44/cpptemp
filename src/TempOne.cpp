            #include <iostream>
            #include "VectorOne.hpp"
            #include <memory>
            #include <string.h>
            #include <stdlib.h>
            #include <sys/types.h>
            #include <unistd.h>
            #include<algorithm>
            #include <sys/wait.h>
        #include <mutex>
        #include <print>
#include <map>
#include <set>

struct CompareVectorOne {
    bool operator()(const VectorOne<std::string> &a, const VectorOne<std::string> &b) const {
        return a.getObjectValue() < b.getObjectValue();
    }
};



            using namespace std;
            int main(){

                    std::srand(std::time(0)); 
                pid_t pid;
                int makme = 1296;
                int makma =   2048;

                std::string riley = "simon riely";
                std::mutex mutexOne;    
        
                std::set<VectorOne<std::string> , CompareVectorOne>  set{
                    
                    
  VectorOne<std::string>(std::string("simon riely")),
  VectorOne<std::string>(std::string("prashanth Nuthula")),
  VectorOne<std::string>(std::string("Mounika Nuthula ")),
  VectorOne<std::string>(std::string("varsha reddy polla ")),
  VectorOne<std::string>(std::string("krishna reddy")),


                };
set.insert(VectorOne<std::string>(std::string("Akhil Nuthula")));

                 
                for(auto & k :  set){
cout << k.getObjectValue() << endl;


                }
                







            return 0;
        }
