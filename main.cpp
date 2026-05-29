#include <cstdio>
#include<iostream>
using namespace std;
class abst{
char *  charas;
  virtual void get()=0; 
  
};


class abstone  :  abst {
int a;
 void get() {
  
   std::cout << "getonr\n" << std::endl;
   
 }
  
  
  
};

int main()
{

abst *b;
std::cout << sizeof(b) <<std::endl;
abstone k ;
  std::cout << sizeof(k)
<<std::endl;

}

