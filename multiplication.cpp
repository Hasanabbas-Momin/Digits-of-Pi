#include <bits/stdc++.h>
#include "header.hpp"
using namespace std;

pair<vector<int>, int> multiplication(vector<int> &a, int a_point, vector<int> &b, int b_point, int precision, int base)
{
    // cout << "in multiplication \n";
    vector<int> c;
    int carry = 0;
    for (int i = 0; i < a.size() + b.size(); i++)
    {
        c.push_back(0);
    }
    for (int i = 0; i < a.size(); i++)
    {
        carry = 0;
        for (int j = 0; j < b.size(); j++)
        {
            int tmp = a[i] * b[j] + carry + c[i + j];
            carry = tmp / base;
            c[i + j] = tmp % base;
        }
        c[b.size() + i] = carry;
    }
    // cout<<
    // if (carry != 0)
    // {
    //     c.push_back(carry);
    // }
    int c_point = (a_point + b_point);
    return make_pair(c, c_point);
}