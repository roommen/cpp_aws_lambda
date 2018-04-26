#include <iostream>
using namespace std;

class File {
private:
    string name;
public:
    File(string name);
    void encrypt();
    void decrypt();
};
