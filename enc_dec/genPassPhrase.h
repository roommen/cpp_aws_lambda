#ifndef GEN_PASSPHRASE_H_
#define GEN_PASSPHRASE_H_

using namespace std;

class PassPhrase {
private:
    string sn;
    string ac;
public:
    PassPhrase(string sn, string ac);
    void display();
    string genPP(string sn, string ac);
};

#endif /* GEN_PASSPHRASE_H_ */
