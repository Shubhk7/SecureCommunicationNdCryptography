#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

string prepKey(string Key)
{
    // transform(str.begin(), str.end(), str.begin(), ::toupper);//convert to uppercase
    string result = "";
    for (char c : Key)
    {
        c = toupper(c);
        if (c == 'J')
        {
            c = 'I';
        }
        if (char(c) >= 'A' && char(c) <= 'Z')
        { // check if character is an alphabet and remove duplicates
            if (result.find(c) == string::npos)
            { // check if character is not already in result
                result += c;
            }
        }
    }
    string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    for (char c : alphabet)
    { // add the remaining letters of the alphabet
        if (result.find(c) == string::npos)
        { // check if character is not already in result
            result += c;
        }
    }
    return result;
}

void createMatrix(string Key, char Matrix[5][5])
{
    string prepedKey = prepKey(Key);
    int k = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            Matrix[i][j] = prepedKey[k++];
        }
    }
}

void findPosition(char Matrix[5][5], char ch, int &row, int &col)
{
    if (ch == 'J')
    {
        ch = 'I';
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (Matrix[i][j] == ch)
            {
                row = i;
                col = j;
                return;
            }
        }
    }
}

string decryptPlayfair(string ciphertext, char Matrix[5][5])
{
    string text = "";
    for (char c: ciphertext)
    {
        c = toupper(c);
        if (c == 'J')
        {
            c = 'I';
        }
        text += c;
    }
    if (text.length() % 2 != 0)
    {
        text += 'X';
    }
    string plaintext = "";
    for (int i = 0; i< text.length(); i+=2)
    {
        char a = text[i];
        char b = text[i+1];

        int r1, c1, r2, c2;
        findPosition(Matrix, a, r1, c1);
        findPosition(Matrix, b, r2, c2);

        if (r1 == r2)
        {
            plaintext += Matrix[r1][(c1 + 4) % 5];
            plaintext += Matrix[r2][(c2 + 4) % 5];
        }
        else if (c1 == c2)
        {
            plaintext += Matrix[(r1 + 4) % 5][c1];
            plaintext += Matrix[(r2 + 4) % 5][c2];
        }
        else
        {
            plaintext += Matrix[r1][c2];
            plaintext += Matrix[r2][c1];
        }
    }
    return plaintext;    
}

void DisplayMatrix(char Matrix[5][5])
{
    cout << "\n\nPlayfair\n\n ";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    string Key, ciphertext;
    cout << "Enter Key: ";
    cin >> Key;
    cout << "Enter Ciphertext: ";
    cin >> ciphertext;
    char Matrix[5][5];
    createMatrix(Key, Matrix);
    DisplayMatrix(Matrix);

    string plaintext = decryptPlayfair(ciphertext, Matrix);
    cout << "\n\nPlaintext: " << plaintext << endl;
    return 0;
}