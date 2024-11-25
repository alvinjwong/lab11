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

