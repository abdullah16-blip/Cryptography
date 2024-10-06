#include <iostream>
#include <string>

using namespace std;

int main() {
    string plaintext = "I LOVE MYCOUNTRY";
    string ciphertext = "";
    string decryptedText = "";

    // // Pad the plaintext to make its length divisible by 3
    // while (plaintext.length() % 3 != 0) {
    //     plaintext += 'X';  // Add 'X' as padding
    // }

    // Encrypt: Shift each character by 3, with wrap-around for alphabetic characters
    for (char ch : plaintext) {
        if (ch >= 'A' && ch <= 'Z') {  // Ensure we are only shifting alphabetic characters
            ciphertext += (ch - 'A' + 3) % 26 + 'A';  // Shift and wrap within 'A' to 'Z'
        } else {
            ciphertext += ch;  // Leave non-alphabetic characters unchanged
        }
    }

    // Decrypt: Reverse the shift by 3, with wrap-around for alphabetic characters
    for (char ch : ciphertext) {
        if (ch >= 'A' && ch <= 'Z') {  // Ensure we are only shifting alphabetic characters
            decryptedText += (ch - 'A' - 3 + 26) % 26 + 'A';  // Reverse shift and wrap within 'A' to 'Z'
        } else {
            decryptedText += ch;  // Leave non-alphabetic characters unchanged
        }
    }

    // Output results
    cout << "Original Plaintext: " << plaintext << endl;
    cout << "Encrypted Ciphertext: " << ciphertext << endl;
    cout << "Decrypted Plaintext: " << decryptedText << endl;

    return 0;
}
