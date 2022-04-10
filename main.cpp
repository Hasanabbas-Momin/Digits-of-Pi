#include <bits/stdc++.h>
#include "header.hpp"
using namespace std;

int main()
{
    pair<vector<int>, int> a;
    a.second = 0;
    a.first.push_back(2);
    int precision, base, choice;
    cin >> choice;
    cin >> precision;
    cin >> base;
    base = 10; // if base not made 10 then final answer also comes in base 2^m (couldn't implement base converter)
    if (choice == 2)
    {
        pair<vector<int>, int> temp = sqrt(a.first, a.second, precision, base);
        // cout << temp.first.size() << " \n";
        for (int i = temp.first.size() - 1; i >= temp.first.size() - precision - 1; i--)
        {
            // cout << "temp\n";
            if (i == temp.second - 1)
                cout << '.';
            cout << temp.first[i];
        }
        cout << "\n";
    }
    else
    {
        pair<vector<int>, int> Pi = pi(precision, base);
        for (int i = Pi.first.size() - 1; i >= Pi.first.size() - precision - 1; i--)
        {
            if (i == Pi.second - 1)
                cout << '.';
            cout << Pi.first[i];
        }
        cout << "\n";
    }
    return 0;
}