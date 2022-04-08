#include <bits/stdc++.h>
#include "header.hpp"
using namespace std;

pair<vector<int>, int> subtraction(vector<int> &x, int x_point, vector<int> &y, int y_point, int precision, int base)
{
    // cout << "in subtraction \n";
    vector<int> a, b;
    int zeros = x_point - y_point;
    vector<int> ans;
    int ans_point = max (x_point, y_point);
    for (int i = 0; i < zeros; i++)
        b.push_back(0);
    for (int i = 0; i < -zeros; i++)
        a.push_back(0);

    for (int i = 0; i < y.size(); i++)
        b.push_back(y[i]);
    for (int i = 0; i < x.size(); i++)
        a.push_back(x[i]);

    int carry = 0;
    int i = 0, j = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] - b[j] + carry < 0)
        {
            ans.push_back(a[i] - b[i] + carry + base);
            carry = -1;
        }
        else
        {
            ans.push_back(a[i] - b[i] + carry);
            carry = 0;
        }
        i++;
        j++;
    }
    while (i < a.size())
    {
        if (a[i] + carry < 0)
        {
            ans.push_back(a[i] + carry + base);
            carry = -1;
        }
        else
        {
            ans.push_back(a[i] + carry);
            carry = 0;
        }
        i++;
    }
    while (j < b.size())
    {
        if (b[j] + carry < 0)
        {
            ans.push_back(b[j] + carry + base);
            carry = -1;
        }
        else
        {
            ans.push_back(b[j] + carry);
            carry = 0;
        }
        j++;
    }
    return make_pair(ans, ans_point);
}
