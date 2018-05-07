#include <iostream>
#include <cstring>
#include "CustomerEncryptDecrypt.h"

using namespace std;

int main(int argc, char **argv) {
    File file(argv[2]);

    // Encrypt the file
    if (strcmp(argv[1], "encrypt") == 0)
        file.encrypt();

    // Decrypt the file
    if (strcmp(argv[1], "decrypt") == 0)
        file.decrypt();

        return 0;
}
