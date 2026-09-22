#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string encryptCaesar(string text, int key)
{
    string result = "";
    key = key % 26;

    for (char ch : text)
    {
        if (isupper(ch))
        {
            result += char((ch - 'A' + key) % 26 + 'A');
        }
        else if (islower(ch))
        {
            result += char((ch - 'a' + key) % 26 + 'a');
        }
        else
        {
            result += ch;
        }
    }

    return result;
}

string decryptCaesar(string text, int key)
{
    string result = "";
    key = key % 26;

    for (char ch : text)
    {
        if (isupper(ch))
        {
            result += char((ch - 'A' - key + 26) % 26 + 'A');
        }
        else if (islower(ch))
        {
            result += char((ch - 'a' - key + 26) % 26 + 'a');
        }
        else
        {
            result += ch;
        }
    }

    return result;
}

void cryptanalysis(string ciphertext)
{
    cout << "\n----- Cryptanalysis -----\n";
    cout << "Trying all possible Caesar keys:\n\n";

    for (int key = 0; key < 26; key++)
    {
        cout << "Key " << key << ": " << decryptCaesar(ciphertext, key) << endl;
    }
}

int main()
{
    string plaintext;
    int key;

    cout << "Enter plaintext message:";
    getline(cin, plaintext);

    cout << "Enter Caesar key:";
    cin >> key;

    key = key % 26;

    string ciphertext = encryptCaesar(plaintext, key);
    string decryptedText = decryptCaesar(ciphertext, key);

    cout << "\n----- Results -----\n";
    cout << "Plaintext: " << plaintext << endl;
    cout << "Key: " << key << endl;
    cout << "Ciphertext: " << ciphertext << endl;
    cout << "Decrypted: " << decryptedText << endl;

    cryptanalysis(ciphertext);

    return 0;
}