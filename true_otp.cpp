#include<bits/stdc++.h>
using namespace std;

// Function to generate a random key of the same length as plaintext
string generateKey(int length) {
    string key = "";
    for (int i = 0; i < length; ++i) {
        key += char(rand() % 256); // Random character from ASCII range
    }
    return key;
}

// Function to encrypt using OTP
string encryptOTP(string plaintext, string key) {
    string ciphertext = "";
    for (int i = 0; i < plaintext.length(); ++i) {
        ciphertext += plaintext[i] ^ key[i]; // XOR each character
    }
    return ciphertext;
}

// Function to decrypt using OTP
string decryptOTP(string ciphertext, string key) {
    string decryptedText = "";
    for (int i = 0; i < ciphertext.length(); ++i) {
        decryptedText += ciphertext[i] ^ key[i]; // XOR each character to decrypt
    }
    return decryptedText;
}

int main() {
    // Input plaintext
    string plaintext = "COMPUTER SCIENCE";
    cout << "Original Plaintext: " << plaintext << endl;

    // Generate a random key of the same length
    srand(time(0)); // Seed random number generator
    string key = generateKey(plaintext.length());
    cout << "Generated Key: ";
    for (char k : key) {
        cout << int(k) << " "; // Print the key as integer values for readability
    }
    cout << endl;

    // Encrypt the plaintext
    string ciphertext = encryptOTP(plaintext, key);
    cout << "Encrypted Ciphertext: ";
    for (char c : ciphertext) {
        cout << int(c) << " "; // Print the ciphertext as integer values
    }
    cout << endl;

    // Decrypt the ciphertext
    string decryptedText = decryptOTP(ciphertext, key);
    cout << "Decrypted Plaintext: " << decryptedText << endl;

    return 0;
}
