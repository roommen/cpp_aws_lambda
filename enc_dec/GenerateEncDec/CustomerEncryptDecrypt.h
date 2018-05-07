#ifndef CUSTOMER_ENCRYPT_DECRYPT_H_
#define CUSTOMER_ENCRYPT_DECRYPT_H_

using namespace std;

class File {
private:
    string filename;
public:
    File(string filename);
    void encrypt();
    void decrypt();
};

#endif /* CUSTOMER_ENCRYPT_DECRYPT_H_ */
