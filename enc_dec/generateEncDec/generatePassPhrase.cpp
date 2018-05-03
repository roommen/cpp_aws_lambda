#include <iostream>
#include "generatePassPhrase.h"

PassPhrase::PassPhrase(string sn, string ac) {
    this->sn = sn;
    this->ac = ac;
}

string PassPhrase::generatePassPhraseString(string sn, string ac) {
    string passphrase = "";
    int j=0, k=0;
    /* Following logic generates passphrase */
    /* "BOS-" prefix is removed from the serial no and then takes first 2 chars each */
    /* The "-" is also removed from authorization code. Appends 1 char from ac along with 2 chars of sn */
    /* A "-" gets added in the middle of sn+ac mixup combination */
    for (unsigned int i = 4; i < sn.length();++i)
    {
        passphrase += sn[i];
        j = ++i;
        passphrase += sn[j];
        i = j;
        passphrase += ac[k];
        if (k == 2) {
            passphrase += "-";
            k++;
        }
        k++;
    }
    return passphrase;
}

/* Create the customer specific passphrase.h file */
void PassPhrase::createPassPhraseHeaderFile(string sha256_pp) {
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
    pp_h.close();
}

