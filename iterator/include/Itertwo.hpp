#include <iostream>

#pragma once


namespace Itertwo{



    struct  IterTwo{

virtual IterTwo* getIterObject(){
return this;    
}

 void greet(){

    std::cout<<"Hello from IterTwo"<<std::endl;
 }



};




}