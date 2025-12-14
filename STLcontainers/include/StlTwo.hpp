#include <iostream>
using namespace std;
class Example
{
public:
    Example(int value) : value(value) {} // Parameterized constructor
    Example() { cout << "  constrcutor of base class" << endl; }
    virtual ~Example() { cout << "destrcutor of base class" << endl; }
    virtual void getins() = 0; // Disable the default constructor

private:
    int value;
};
class imp : public Example
{
public:
    imp()
    {
        cout << "derrieved class constructor" << endl;
    }

    ~imp() { cout << "  destructor of  derrieved" << endl; }

  __attribute__((__always_inline__))  inline    void getins() 
    {

        
        cout << "this" << endl;
    }
};
