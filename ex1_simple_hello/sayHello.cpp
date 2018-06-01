#include "sayHello.h"

SayHello::SayHello(string name): name(name) {}

string SayHello::say() {
    return "Hello " + name;
}
