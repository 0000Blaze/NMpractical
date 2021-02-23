#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num;
    float val, a, b, h, sum;
    vector<float> y;
    cout << "Enter the number of strips: ";
    cin >> num;
    cout << "Enter the limits of integration(a, b): ";
    cin >> a >> b;
    for (int i = 0; i <= num; i++)
    {
        cout << "Y" << i << ": ";
        cin >> val;
        y.push_back(val);
    }

    h = (b - a) / num;
    sum = y[0] + y[num];

    for (int i = 1; i < num; i++)
    {
        sum += 2 * y[i];
    }

    sum *= h / 2;

    cout << "Result = " << sum;
}