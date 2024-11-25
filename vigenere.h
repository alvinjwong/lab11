#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>


class Vigenere {
    public:
    Vigenere(std::string key);

    ~Vigenere();

    std::string encrypt(std::string msg);

    std::string decrypt(std::string msg);

    bool isEncrypted(std::string encryptedMsg, std::string decryptedMessage);

    void setKey(std::string key);

    private:
    std::string key_t;
    
    std::string repeatKey(std::string msg);

};

#endif