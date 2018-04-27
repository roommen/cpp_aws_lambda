#include <iostream>
#include "genPassPhrase.h"

PassPhrase::PassPhrase(string sn, string ac) {
    this->sn = sn;
    this->ac = ac;
}

void PassPhrase::display() {
    cout << "sn: " << sn << " ac: " << ac << endl;
}

string PassPhrase::genPP(string sn, string ac) {
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
