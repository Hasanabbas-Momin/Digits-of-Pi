#include <bits/stdc++.h>
#include "header.hpp"
using namespace std;

int main()
{
    pair<vector<int>, int> a;
    a.second = 0;
    a.first.push_back(2);
    int precision, base;
    cin >> precision;
    cin >> base;
    pair<vector<int>, int> temp = multiplication(a.first, a.second, a.first, a.second, precision, base);
    // pair<vector<int>, int> temp = sqrt(a.first, a.second, precision, base);
    cout << temp.first.size() << " \n";
    for (int i = temp.first.size() - 1; i >= temp.first.size() - precision - 1; i--)
    {
        // cout << "temp\n";
        if (i == temp.second - 1)
            cout << '.';
        cout << temp.first[i];
    }
    cout << "\n";
    pair<vector<int>, int> Pi = pi(precision, base);
    for (int i = Pi.first.size() - 1; i >= Pi.first.size() - precision - 1; i--)
    {
        if (i == Pi.second - 1)
            cout << '.';
        cout << Pi.first[i];
    }
    cout << "\n";
    return 0;
}