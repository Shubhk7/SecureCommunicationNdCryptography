#include <iostream>
#include <cmath>
using namespace std;

double euclidianAlgo(double a, double b)
{
    a = abs(a);
    b = abs(b);
    double GCD, R, r1, r2;
    r1 = a;
    r2 = b;
    while (r2 > 1e-12)
    {
        R = fmod(r1, r2);
        r1 = r2;
        r2 = R;
        GCD = r1;
    }
    return GCD;
}

int main()
{
    double a, b;
    cout << "Enter Both num:";
    cin >> a >> b;
    cout << euclidianAlgo(a, b) << endl;
    // cout << 45 % 56;
    return 0;
}