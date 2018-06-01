#ifndef SAY_HELLO_H
#define SAY_HELLO_H

#include <iostream>
#include <string>

using namespace std;

class SayHello {
public:
    SayHello(string name);
    string say();
private:
    string name;
};

#endif /* SAY_HELLO_H */
