#ifndef PRIME_H_
#define PRIME_H_

#include <iostream>
#include <vector>

using namespace std;

class Prime {
private:
    string name;
public:
    Prime();
    string genPrimes(const char* primeLimit);
};

#endif /* PRIME_H_ */
