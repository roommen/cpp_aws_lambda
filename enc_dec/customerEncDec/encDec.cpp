#include "encDec.h"
#include "passphrase.h"

#define MAX_CMD_LEN 256

File::File(char *filename) {
    this->filename = filename;
}

void File::encrypt() {
    char cmd[MAX_CMD_LEN*2] = {'\0'};

    snprintf(cmd, MAX_CMD_LEN*2, "cd ../sampleFiles; echo %s | gpg  --batch --passphrase-fd 0 --output "
     "%s.enc --symmetric --cipher-algo AES256 %s; cd ..\n", CUSTOMER_PASSPHRASE, filename, filename);
     system(cmd);
}

void File::decrypt() {
    cout << "Decrypt file" << endl;
    // Decryption command:
    // echo CUSTOMER_PASSPHRASE | gpg --batch --passphrase-fd 0 
    // --output age_gender.py --decrypt age_gender.py.enc
}
