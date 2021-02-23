#include <iostream>
#include <cmath>

using namespace std;

float funcVal(float x)
{
    return x*x -34.43;
}

int main()
try
{
    int num, m;
    float a, b, h, sum, x;
    cout << "For x*x -34.43" << endl;
    cout << "Enter the number of strips: ";
    cin >> num;
    cout << "Enter the limits of integration(a, b): ";
    cin >> a >> b;
    if (num % 3 != 0)
        throw 0;

    h = (b - a) / num;
    sum = funcVal(a) + funcVal(b);

    for (int i = 1; i < num; i++)
    {
        m = (i % 3 == 0) ? 2 : 3;
        x = a + i * h;
        sum += m * funcVal(x);
    }

    sum *= 3 * h / 8;

    cout << "Result = " << sum;
}
catch (int n)
{
    cout << "Exception: Number of strips not divisible by 3";
}
