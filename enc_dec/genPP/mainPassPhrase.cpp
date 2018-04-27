#include <iostream>
#include <fstream>
#include "genPassPhrase.h"
#include "sha256.h"

#define PASSPHRASE_H "passphrase.h"

using namespace std;

/* Create the customer specific passphrase.h file */
void createCustomerPassPhraseHeaderFile(string sha256_pp) {
    ofstream pp_h;
    pp_h.open(PASSPHRASE_H, ios::out|ios::trunc);
    pp_h << "#ifndef PASSPHRASE_H_" << endl;
    pp_h << "#define PASSPHRASE_H_" << endl;
    pp_h << endl;
    pp_h << "/* This file is generated dynamically */" << endl;
    pp_h << "/* Passphrase created from SHA256 value of SN and AC after custom re-arrangement */" << endl;
    pp_h << "#define CUSTOMER_PASSPHRASE \"" << sha256_pp << "\"" << endl;
    pp_h << endl;
    pp_h << "#endif /* PASSPHRASE_H_ */" << endl;
}

int main(int argc, char **argv) {
    PassPhrase pp(argv[1], argv[2]);

    string passphrase = pp.genPP(argv[1], argv[2]);
    string sha256_pp = sha256(passphrase);
    cout << "passphrase is " << passphrase << endl;
    cout << "sha256 passphrase is " << sha256_pp << endl;

    createCustomerPassPhraseHeaderFile(sha256_pp);

    return 0;
}
