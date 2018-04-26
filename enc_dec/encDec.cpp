#include <iostream>
#include "passphrase.h"

using namespace std;

class File {
private:
    string name;
public:
    File(string name): name(name) {}
    void encrypt();
    void decrypt();
};

int main(int argc, char **argv) {


    return 0;
}
