#ifndef HELLO_H_
#define HELLO_H_

#include <iostream>

using namespace std;

class Hello {
private:
    string name;
public:
    Hello(string name);
    void sayHello();
};

#endif /* HELLO_H_ */
