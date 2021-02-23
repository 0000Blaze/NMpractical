//For y = ae^(bx)

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cout << "Enter number of entries: ";
    cin >> n;
    pair<float, float> value, ans;
    vector<pair<float, float>> valueVec;
    float sumX = 0, sumY = 0, sumX2 = 0, sumXY = 0, D1, D2, D3, a, b;
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << ": ";
        cin >> value.first;
        cout << "y" << i + 1 << ": ";
        cin >> value.second;
        sumX += value.first;
        sumY += log(value.second);
        sumX2 += value.first * value.first;
        sumXY += (value.first) * log(value.second);
        valueVec.push_back(value);
        cout << endl;
    }
    // << sumX << " " << sumY << " " << sumXY << " " << sumX2 << endl;
    //Find Value of Constants
    D1 = sumY * sumX2 - sumXY * sumX;
    D2 = n * sumXY - sumX * sumY;
    D3 = n * sumX2 - sumX * sumX;
    a = exp(D1 / D3);
    b = D2 / D3;
    cout << "a = " << a << " and b = " << b << endl;
    cout << "The required curve is y = " << setprecision(4) << a << "e^" << b << "x" << endl;
}
