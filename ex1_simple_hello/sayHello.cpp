#include "sayHello.h"

SayHello::SayHello(string name): name(name) {}

void SayHello::sayHello() {
    cout << "Hello " << name << endl;
}
