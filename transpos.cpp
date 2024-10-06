#include<bits/stdc++.h>
using namespace std;

// Function to pad the plaintext
// string padPlaintext(string plaintext, int width) {
//     // while (plaintext.length() % width != 0) {
//     //     plaintext += 'X';  // Add padding 'X'
//     // }
//     return plaintext;
// }

// Function to encrypt using transposition cipher
string encryptTransposition(string plaintext, int width) {
    string ciphertext = "";
    int rows = ceil((double)plaintext.length() / width);

    // Read column by column to form the ciphertext
    for (int j = 0; j < width; ++j) {
        for (int i = 0; i < rows; ++i) {
            int index = i * width + j;
            if (index < plaintext.length()) {
                ciphertext += plaintext[index];
            }

        }
    }

    return ciphertext;
}

// Function to decrypt using transposition cipher
string decryptTransposition(string ciphertext, int width) {
    int rows = ceil((double)ciphertext.length() / width);
    string plaintext = "";

    // Read row by row to form the plaintext
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < width; ++j) {
            int index = j * rows + i;
            if (index < ciphertext.length()) {
                plaintext += ciphertext[index];
            }
        }
    }

    return plaintext;
}

int main() {
    // Input plaintext
    string plaintext = "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING";//AND TECHNOLOGY UNIVERSITY OF RAJSHAHI BANGLADESH
    cout << "Original Plaintext: " << plaintext << endl;

    // Get width input
    int width;
    cout << "Enter the width for transposition cipher: ";
    cin >> width;

    // Remove spaces and pad the plaintext
    // plaintext.erase(remove(plaintext.begin(), plaintext.end(), ' '), plaintext.end());
    // plaintext = padPlaintext(plaintext, width);

    // Encrypt and decrypt
    string ciphertext = encryptTransposition(plaintext, width);
    cout << "Encrypted Ciphertext: " << ciphertext << endl;

    string decryptedText = decryptTransposition(ciphertext, width);
    cout << "Decrypted Plaintext: " << decryptedText << endl;

    return 0;
}
