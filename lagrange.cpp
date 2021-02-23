#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

float findValue(vector<pair<float, float>> valuesVec, float x)
{
    float y = 0, val;
    for (int i = 0; i < valuesVec.size(); i++)
    {
        val = 1;
        for (int j = 0; j < valuesVec.size(); j++)
        {
            if (i != j)
                val = val * (x - valuesVec[j].first) / (valuesVec[i].first - valuesVec[j].first);
        }
        y += val * valuesVec[i].second;
    }
    return y;
}

int main()
{
    pair<float, float> values;
    vector<pair<float, float>> valuesVec;
    int size;
    float x;
    cout << "Enter number of entries: ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "x" << i + 1 << ": ";
        cin >> values.first;
        cout << "y" << i + 1 << ": ";
        cin >> values.second;
        valuesVec.push_back(values);
        cout << endl;
    }
    cout << "Enter x to find y(x): ";
    cin >> x;
    cout << "y(" << x << ")"
         << " = " << findValue(valuesVec, x);
}
