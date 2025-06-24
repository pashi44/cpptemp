#include <iostream>
#include <string>
#include <stdlib.h>
#include <sys/types.h>
#include <chrono>
#include <unistd.h>
using namespace std;

class Abstract {
    public:
        virtual void foo() = 0;
        char c = 'A';
    };
    
    class Derived : public Abstract {
    public:
        int b = 42;
        void foo() override {
            cout << "Derived::foo" << endl;
        }
    };
    
    class Thirved : public Abstract {
    public:
        int x = 99;
        void foo() override {
            cout << "Thirved::foo" << endl;
        }
    };







    int main() {
        Derived d;
        Thirved t;
    
        Abstract* ptr1 = &d;
        Abstract* ptr2 = &t;
    
        // Access vptrs
        void** vptr_d = *(void***)&d;
        void** vptr_t = *(void***)&t;
    
        cout << "Object d address:         " << &d << endl;
        cout << "vptr for Derived:         " << vptr_d << endl;
        cout << "Derived::vtable[0] (RTTI):" << vptr_d[0] << endl;
        cout << "Derived::vtable[1] (foo): " << vptr_d[1] << endl;
    
        cout << "Object t address:         " << &t << endl;
        cout << "vptr for Thirved:         " << vptr_t << endl;
        cout << "Thirved::vtable[0] (RTTI):" << vptr_t[0] << endl;
        cout << "Thirved::vtable[1] (foo): " << vptr_t[1] << endl;
    
        // Call virtual via vtable manually
        using FnType = void(*)(Abstract*);
        FnType dfunc = (FnType)vptr_d[1];
        FnType tfunc = (FnType)vptr_t[1];
    
        dfunc(ptr1); // calls Derived::foo
        tfunc(ptr2); // calls Thirved::foo
    
        return 0;
    }
