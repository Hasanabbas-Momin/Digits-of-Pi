#include <bits/stdc++.h>
#include "header.hpp"
using namespace std;

pair<vector<int>, int> addition(vector<int> &x,int x_point, vector<int> &y, int y_point, int precision, int base)
{
    // cout << "in addition \n";
    vector<int> a;
    vector<int> b;
    int carry = 0;
    int i = 0, j = 0;
    vector<int> ans;
    int zeros = x_point - y_point;
    int ans_point = max(x_point, y_point);
    for (int i = 0; i < zeros; i++)
        b.push_back(0);
    for (int i = 0; i < -zeros; i++)
        a.push_back(0);

    for (int i = 0; i < y.size(); i++)
        b.push_back(y[i]);
    for(int i = 0; i < x.size(); i++)
        a.push_back(x[i]);
    int sum = 0, temp;
    while (i < a.size() && j < b.size())
    {
        temp = a[i] + b[j] + carry;
        sum = temp % base;
        carry = (sum < temp) ? 1 : 0;
        ans.push_back(sum);
        i ++;
        j ++;
    }
    //     if (a[i] + b[j] + carry >= base)
    //     {
    //         ans.push_back(a[i] + b[i] + carry - base);
    //         carry = 1;
    //     }
    //     else
    //     {
    //         ans.push_back(a[i] + b[i] + carry);
    //         carry = 0;
    //     }
    //     i++;
    //     j++;
    // }
    while (i < a.size())
    {
        temp = a[i] + carry;
        sum = temp % base;
        carry = (sum < temp) ? 1: 0;
        ans.push_back(sum);
        i++;
        // if (a[i] + carry >= base)
        // {
        //     ans.push_back(a[i] + carry - base);
        //     carry = 1;
        // }
        // else
        // {
        //     ans.push_back(a[i] + carry);
        //     carry = 0;
        // }
        // i++;
    }
    while (j < b.size())
    {
        temp = b[j] + carry;
        sum = temp%base;
        carry = (sum < temp) ? 1 : 0;
        ans.push_back(sum);
        j++;
        // if (b[j] + carry >= base)
        // {
        //     ans.push_back(b[j] + carry - base);
        //     carry = 1;
        // }
        // else
        // {
        //     ans.push_back(b[j] + carry);
        //     carry = 0;
        // }
        // j++;
    }
    if (carry > 0)
    {
        ans.push_back(carry);
    }
    return make_pair(ans, ans_point);
}
