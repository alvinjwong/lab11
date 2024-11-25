#include "vigenere.h"
#include <cctype>
#include <algorithm>

Vigenere::Vigenere(std::string key) : key(std::move(key)) {}

Vigenere::~Vigenere() {}

std::string Vigenere::repeatKey(std::string msg) {
    std::string repeatedKey;
    int keyIndex = 0;
    for (char c : msg) {
        if (std::isalpha(c)) {
            repeatedKey += key[keyIndex];
            keyIndex = (keyIndex + 1) % key.size();
        }
    }
    return repeatedKey;
}

std::string Vigenere::encrypt(std::string msg) {
    std::string encrypted;
    std::string repeatedKey = repeatKey(msg);
    for (int i = 0; i < msg.size(); i++) {
        if (std::isalpha(msg[i])) {
            char shift = repeatedKey[i] - 'A';
            char encry = ((msg[i] - 'A' + shift) % 26) + 'A';
            encrypted += encry;
        } else {
            encrypted += msg[i];
        }
    }
    return encrypted;
}

std::string Vigenere::decrypt(std::string msg) {
    std::string decrypted;
    std::string repeatedKey = repeatKey(msg);
    for (int i = 0; i < msg.size(); i++) {
        if (std::isalpha(msg[i])) {
            char shift = repeatedKey[i] - 'A';
            char decry = ((msg[i] - 'A' - shift + 26) % 26) + 'A';
            decrypted += decry;
        } else {
            decrypted += msg[i];
        }
    }
    return decrypted;
}

bool Vigenere::isEncrypted(std::string encryptedMsg, std::string decryptedMessage) {
    return encrypt(decryptedMessage) == encryptedMsg;
}

void Vigenere::setKey(std::string key) {
    this->key = std::move(key);
}
