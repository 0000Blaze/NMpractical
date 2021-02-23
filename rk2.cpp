#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float funcVal(float x, float y)
{
    return 2.2*sin(x/2);
}

int main()
{
    float x0, y0, xn, yn, n, h, k1, k2, k;
    cout << "For 2.2* sin^(x/2)" << endl;
    cout << "Enter intital values(x0 and y0):";
    cin >> x0 >> y0;
    cout << "Enter final value of x(xn): ";
    cin >> xn;
    cout << "Enter number of steps: ";
    cin >> n;
    h = (xn - x0) / n;
    cout << "\nX\tY\tYnew\n";
    for (int i = 0; i < n; i++)
    {
        k1 = h * funcVal(x0, y0);
        k2 = h * funcVal(x0 + h, y0 + k1);
        k = (k1 + k2) / 2;
        yn = y0 + k;
        cout << setprecision(4) << x0 << "\t" << y0 << "\t"
             << yn << endl;
        y0 = yn;
        x0 = x0 + h;
    }
    cout << "\nValue of y at x = " << xn << " is " << yn;
}
