#include "hello.h"

Hello::Hello(string name) {
	this->name = name;
}

void Hello::sayHello()
{
	cout << "Hello, " << name << endl;
}
