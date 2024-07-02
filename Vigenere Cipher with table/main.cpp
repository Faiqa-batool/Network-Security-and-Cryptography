#include <iostream>
#include <string>

using namespace std;

// Function to create the Vigenere cipher matrix
char vigenereMatrix[26][26];

void createVigenereMatrix() {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            vigenereMatrix[i][j] = (char) ((i + j) % 26 + 'A');
        }
    }
}

// Function to find the intersection of plaintext and keyword in the Vigenere cipher matrix
char findIntersection(char plaintext, char keyword) {
    int plaintextIndex = plaintext - 'A';
    int keywordIndex = keyword - 'A';
    return vigenereMatrix[keywordIndex][plaintextIndex];
}

// Function to perform Vigenere cipher encryption
string vigenereEncrypt(string plaintext, string key) {
    string encryptedText = "";

    cout << "Vigenere Cipher Matrix:" << endl;
    // Print the Vigenere cipher matrix
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            cout << vigenereMatrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nEncryption Process:" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "| Plain Text | Key Char | Intersection | Encrypted Char |" << endl;
    cout << "--------------------------------------------------------" << endl;

    // Iterate over each character in the plaintext
    for (int i = 0; i < plaintext.length(); i++) {
        char plaintextChar = toupper(plaintext[i]);
        char keywordChar = toupper(key[i % key.length()]);
        char intersection = findIntersection(plaintextChar, keywordChar);
        encryptedText += intersection;

        // Print the encryption process
        printf("|     %c     |    %c     |      %c       |        %c        |\n",
               plaintextChar, keywordChar, intersection, intersection);
    }
    cout << "--------------------------------------------------------" << endl;

    return encryptedText;
}

// Function to perform Vigenere cipher decryption
string vigenereDecrypt(string encryptedText, string key) {
    string decryptedText = "";

    cout << "\nDecryption Process:" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "| Encrypted Char | Key Char | Intersection | Plain Text |" << endl;
    cout << "--------------------------------------------------------" << endl;

    // Iterate over each character in the encrypted text
    for (int i = 0; i < encryptedText.length(); i++) {
        char encryptedChar = toupper(encryptedText[i]);
        char keywordChar = toupper(key[i % key.length()]);

        // Find the position of keywordChar in the first column
        int keywordIndex = keywordChar - 'A';

        // Find the position of encryptedChar in the keyword's row
        int encryptedIndex = -1;
        for (int j = 0; j < 26; j++) {
            if (vigenereMatrix[keywordIndex][j] == encryptedChar) {
                encryptedIndex = j;
                break;
            }
        }

        // If encryptedChar is found in the keyword's row
        if (encryptedIndex != -1) {
            // Find the corresponding plaintext character
            char decryptedChar = 'A' + encryptedIndex;
            decryptedText += decryptedChar;
        } else {
            // If encryptedChar is not found in the keyword's row, add '?' as a placeholder
            decryptedText += '?';
        }

        // Print the decryption process
        printf("|     %c     |    %c     |      %c       |      %c     |\n",
               encryptedChar, keywordChar, encryptedChar, decryptedText[i]);
    }
    cout << "--------------------------------------------------------" << endl;

    return decryptedText;
}

int main() {
    createVigenereMatrix();

    // Input plaintext and key
    cout << "Enter the plaintext: ";
    string plaintext;
    cin >> plaintext;

    cout << "Enter the key: ";
    string key;
    cin >> key;

    // Encryption
    string encryptedText = vigenereEncrypt(plaintext, key);
    cout << "Encrypted Text: " << encryptedText << endl;

    // Decryption
    string decryptedText = vigenereDecrypt(encryptedText, key);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}

