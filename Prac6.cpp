#include <iostream>
#include <iomanip>
using namespace std;

const int Poly = 0b1011;

int gfAdd(int a, int b)
{
    return a ^ b;
}
int gfMultiply(int a, int b){
    int result = 0;

    while (b>0){
        if (b&1){
            result ^= a;
            b>>=1;
            a<<=1;
        }
        for (int i = 6; i>=3; i--){
            if (result & (1 << i)){
                result ^= Poly << (i-3);
            }
        }
    }
    return result;
}

void printAdditionTable(){
    cout << "Addition Table GF 2^3:\n";
    for (int i = 0; i < 8; i++){
        cout << setw(3) << i;
        for (int j = 0; j < 8; j++){
            cout << setw(3) << gfAdd(i, j);
        }
        cout << endl;
    }
}

void printMultiplicationTable(){
    cout << "Multiplication Table GF 2^3:\n";
    for (int i = 0; i < 8; i++){
        cout << setw(3) << i;
        for (int j = 0; j < 8; j++){
            cout << setw(3) << gfMultiply(i, j);
        }
        cout << endl;
    }
}

int main(){
    cout<<"GF(2^3)␣using␣irreducible␣polynomial␣x^3␣+␣x␣+␣1\n";
    cout << "Field Elements: ";
    cout <<"0 = 000 = 0\n";
    cout <<"1 = 001 = 1\n";
    cout <<"2 = 010 = 2\n";
    cout <<"3 = 011 = 3\n";
    cout <<"4 = 100 = 4\n";
    cout <<"5 = 101 = 5\n";
    cout <<"6 = 110 = 6\n";
    cout <<"7 = 111 = 7\n";
    printAdditionTable();
    printMultiplicationTable();
    return 0;
}