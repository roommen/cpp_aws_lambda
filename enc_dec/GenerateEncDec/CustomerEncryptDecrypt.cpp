#include <iostream>
#include "CustomerEncryptDecrypt.h"
#include "passphrase.h"

#define MAX_CMD_LEN 256

File::File(string filename) {
    this->filename = filename;
}

void File::encrypt() {
    char cmd[MAX_CMD_LEN] = {'\0'};

    snprintf(cmd, MAX_CMD_LEN*2, "cd ../sampleFiles; echo %s | gpg --batch --passphrase-fd 0 --output "
     "%s.enc --symmetric --cipher-algo AES256 %s; cd ..\n", CUSTOMER_PASSPHRASE, filename.c_str(), filename.c_str());
     system(cmd);
}

void File::decrypt() {
    char cmd[MAX_CMD_LEN] = {'\0'};
    cout << "cmd: " << cmd;
    snprintf(cmd, MAX_CMD_LEN*2, "cd ../sampleFiles; echo %s | gpg --batch --passphrase-fd 0 --output "
     "%s --decrypt %s.enc; cd ..\n", CUSTOMER_PASSPHRASE, filename.c_str(), filename.c_str());
     system(cmd);
}
