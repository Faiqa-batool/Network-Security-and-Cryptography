#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

// Function to convert a character to its corresponding numerical value (0-25)
int charToValue(char ch) {
    return ch - 'A';
}

// Function to convert a numerical value (0-25) to its corresponding character
char valueToChar(int value) {
    return static_cast<char>(value + 'A');
}

// Function to perform Vigenère cipher encryption and return the result as a string
string vigenereEncryptText(const string& plaintext, const string& key) {
    string encryptedText;

    for (size_t i = 0; i < plaintext.length(); i++) {
        char plainChar = plaintext[i];
        char keyChar = key[i % key.length()];

        int plainValue = charToValue(plainChar);
        int keyValue = charToValue(keyChar);

        int encryptedValue = (plainValue + keyValue) % 26;
        char encryptedChar = valueToChar(encryptedValue);

        encryptedText.push_back(encryptedChar);
    }

    return encryptedText;
}

// Function to perform Vigenère cipher decryption and return the result as a string
string vigenereDecryptText(const string& encryptedText, const string& key) {
    string decryptedText;

    for (size_t i = 0; i < encryptedText.length(); i++) {
        char encryptedChar = encryptedText[i];
        char keyChar = key[i % key.length()];

        int encryptedValue = charToValue(encryptedChar);
        int keyValue = charToValue(keyChar);

        int decryptedValue = (encryptedValue - keyValue + 26) % 26;
        char decryptedChar = valueToChar(decryptedValue);

        decryptedText.push_back(decryptedChar);
    }

    return decryptedText;
}

// Function to perform Vigenère cipher encryption and display the process
void vigenereEncrypt(const string& plaintext, const string& key) {
    cout << "Encryption Process:" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << "| Plain Text | Pi Values | Key Stream | Cipher Values | Cipher Text |" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    for (size_t i = 0; i < plaintext.length(); i++) {
        char plainChar = plaintext[i];
        char keyChar = key[i % key.length()];

        int plainValue = charToValue(plainChar);
        int keyValue = charToValue(keyChar);

        int encryptedValue = (plainValue + keyValue) % 26;

        cout << "|     " << plainChar << "     |    " << setw(2) << plainValue << "     |     " << keyChar
             << "      |      " << setw(2) << encryptedValue << "        |     " << valueToChar(encryptedValue) << "      |" << endl;
    }
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Cipher Text: " << vigenereEncryptText(plaintext, key) << endl;
}

// Function to perform Vigenère cipher decryption and display the process
void vigenereDecrypt(const string& encryptedText, const string& key) {
    cout << "\nDecryption Process:" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << "| Cipher Text | Cipher Values | Key Stream | Pi Values | Plain Text |" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    for (size_t i = 0; i < encryptedText.length(); i++) {
        char encryptedChar = encryptedText[i];
        char keyChar = key[i % key.length()];

        int encryptedValue = charToValue(encryptedChar);
        int keyValue = charToValue(keyChar);

        int decryptedValue = (encryptedValue - keyValue + 26) % 26;
        char decryptedChar = valueToChar(decryptedValue);

        cout << "|     " << encryptedChar << "     |      " << setw(2) << encryptedValue << "       |     " << keyChar
             << "      |     " << setw(2) << decryptedValue << "     |     " << decryptedChar << "     |" << endl;
    }
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Decrypted Text: " << vigenereDecryptText(encryptedText, key) << endl;
}

int main() {
    cout << "Enter the plaintext: ";
    string plaintext;
    getline(cin, plaintext);
    transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::toupper);

    cout << "Enter the key: ";
    string key;
    getline(cin, key);
    transform(key.begin(), key.end(), key.begin(), ::toupper);

    vigenereEncrypt(plaintext, key);
    cout << endl;

    // Perform decryption using the result of encryption
    vigenereDecrypt(vigenereEncryptText(plaintext, key), key);

    return 0;
}

