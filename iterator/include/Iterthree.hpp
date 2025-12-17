#include "Itertwo.hpp"




namespace Iterthree{

    struct IterThree : public Itertwo::IterTwo {
          IterTwo* getIterObject() override {
            return this;
        }


int gte(){

    return 256;
}


    };

}