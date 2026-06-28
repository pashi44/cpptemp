#include <iostream>

#include <future>

using namespace std;

// The exact same 64-byte object from your previous tes

int do_math(){
int k =0;
for(int i =0 ; i < 100000000  ; i++){
    k++;


    cout  << "k = " << k << endl;
}

return k ; 

}


int main(){



std::thread th(&do_math);


cout << "main  thred" << endl;   
th.join();



        return 0;
}