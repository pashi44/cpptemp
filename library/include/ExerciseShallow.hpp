#ifndef  EXERCISE_SHALLOW_HPP
#define  EXERCISE_SHALLOW_HPP

#include <iostream>


 namespace Copying {

    class ExerciseShallow {
    public:
ExerciseShallow(){
    data = new int[10];
for(int i = 0; i < 10; ++i) {
    data[i] = i*i; 

}



}

void  PrintData() const {
    for(int i = 0; i < 10; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

~ExerciseShallow() {
    delete[] data;
}       

private:
    int * data;




 };

}


#endif // ! EXCERSIE
