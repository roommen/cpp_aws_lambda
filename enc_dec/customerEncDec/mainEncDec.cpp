#include <iostream>
#include "encDec.h"

using namespace std;

int main(int argc, char **argv) {
    File file(argv[1]);
    file.encrypt();

    return 0;
}
