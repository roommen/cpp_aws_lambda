#ifndef GENERATE_PASSPHRASE_H_
#define GENERATE_PASSPHRASE_H_

using namespace std;

class PassPhrase {
private:
    string sn;
    string ac;
public:
    PassPhrase(string sn, string ac);
    string generatePassPhraseString(string sn, string ac);
    void createPassPhraseHeaderFile(string sha256_pp);
};

#endif /* GENERATE_PASSPHRASE_H_ */
