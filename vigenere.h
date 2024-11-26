#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>


class Vigenere {
    public:
    /**
    * @brief constructs vigenere object with a key
    * @param key
    */
    Vigenere(std::string key);

/** 
*@brief destructor for the vigenere
*/
    ~Vigenere();

/**
 * @brief encrypts a text message using the current key
 * each letter is shifted forwards in the alphabet based on the corresponding letter in the key
 * @param msg
 * @return encrypted message
 */
    std::string encrypt(std::string msg);

/**
 * @brief decrypts the encrypted message using the key
 * each letter is shifted backwards in the alphabet based on the corresponding letter in the key
 * @param msg
 * @return decrypted message
 */
    std::string decrypt(std::string msg);

/**
 * @brief checks to see if encrypted message matches the decrypted message
 * 
 * @param encryptedMsg
 * @param decryptedMessage
 * @return True if decrypted message matches original message, false if not
 */
    bool isEncrypted(std::string encryptedMsg, std::string decryptedMessage);

/**
 * @brief sets a new key
 * @param key
 */
    void setKey(std::string key);

    private:
    std::string key;
    /**
     * @brief key used for encryption/decryption
     */
    
    std::string repeatKey(std::string msg);
    /**
     * @brief repeats key to match length of message
     * @param msg
     */

};

#endif