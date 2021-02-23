#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float funcVal(float x, float y)
{
    return 22*x*x +1;
}

int main()
{
    float x0, y0, xn, yn, n, h, slope;
    cout << "For 22*x^2 +1" << endl;
    cout << "Enter intital values(x0 and y0):";
    cin >> x0 >> y0;
    cout << "Enter final value of x(xn): ";
    cin >> xn;
    cout << "Enter number of steps: ";
    cin >> n;
    h = (xn - x0) / n;
    cout << "\nX\tY\tSlope\tYnew\n";
    for (int i = 0; i < n; i++)
    {
        slope = funcVal(x0, y0);
        yn = y0 + h * slope;
        cout << setprecision(4) << x0 << "\t" << y0 << "\t" << slope << "\t" << yn << endl;
        y0 = yn;
        x0 = x0 + h;
    }
    cout << "\nValue of y at x = " << xn << " is " << yn;
}
