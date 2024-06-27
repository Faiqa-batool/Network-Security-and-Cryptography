#include <iostream>
using namespace std;

// Function to perform Caesar Cipher encryption
string encrypt(string text, int s) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i]))
            result += char(int(text[i] + s - 65) % 26 + 65);
        else
            result += char(int(text[i] + s - 97) % 26 + 97);
    }

    return result;
}

// Function to perform Caesar Cipher decryption
string decrypt(string text, int s) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i]))
            result += char(int(text[i] - s - 65 + 26) % 26 + 65);
        else
            result += char(int(text[i] - s - 97 + 26) % 26 + 97);
    }

    return result;
}

int main() {
    string text;
    int s;

    // Taking user input for text and shift
    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the shift value: ";
    cin >> s;

    // Encrypting and printing the encrypted text
    string encryptedText = encrypt(text, s);
    cout << "Encrypted Text: " << encryptedText << endl;

    // Decrypting and printing the decrypted text
    string decryptedText = decrypt(encryptedText, s);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
