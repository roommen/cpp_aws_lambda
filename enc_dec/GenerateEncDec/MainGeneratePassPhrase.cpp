#include <iostream>
#include <fstream>
#include "GeneratePassPhrase.h"
#include "SHA256.h"

using namespace std;

int main(int argc, char **argv) {
    PassPhrase pp(argv[1], argv[2]);

    string passphrase = pp.genPP(argv[1], argv[2]);
    string sha256_pp = sha256(passphrase);
    // cout << "passphrase is " << passphrase << endl;
    // cout << "sha256 passphrase is " << sha256_pp << endl;

    pp.createPassPhraseHeaderFile(sha256_pp);

    return 0;
}
