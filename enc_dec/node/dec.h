#include <iostream>
using namespace std;

class File {
private:
    char *filename;
public:
    File(char *filename);
    void encrypt();
    void decrypt();
};
