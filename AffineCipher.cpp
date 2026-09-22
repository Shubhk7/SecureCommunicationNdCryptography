#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char encryptChar(char ch, int a, int b)
{
    if (isupper(ch))
    {
        int P = ch - 'A';
        int C = (a * P + b) % 26;
        return char(C + 'A');
    }
    else if (islower(ch))
    {
        int P = ch - 'a';
        int C = (a * P + b) % 26;
        return char(C + 'a');
    }
    return ch;
}

char decryptChar(char ch, int a, int b)
{
    int inverse = 15;

    if (isupper(ch))
    {
        int C = ch - 'A';
        int P = (inverse * (C - b + 26)) % 26;
        return char(P + 'A');
    }
    else if (islower(ch))
    {
        int C = ch - 'a';
        int P = (inverse * (C - b + 26)) % 26;
        return char(P + 'a');
    }
    return ch;
}

string encrypt(string message, int a, int b)
{
    string result = "";

    for (char ch : message)
    {
        result += encryptChar(ch, a, b);
    }
    return result;
}

string decrypt(string message, int a, int b)
{
    string result = "";
    for (char ch : message)
    {
        result += decryptChar(ch, a, b);
    }
    return result;
}
int main()
{
    string message;
    int a, b;

    cout << "Enter message:";
    getline(cin, message);

    cout << "Enter key a:";
    cin >> a;

    cout << "Enter key b:";
    cin >> b;

    string ciphertext = encrypt(message, a, b);
    cout << "\nCiphertext: " << ciphertext << endl;
    string plaintext = decrypt(ciphertext, a, b);
    cout << "Decrypted text: " << plaintext << endl;
    return 0;
}