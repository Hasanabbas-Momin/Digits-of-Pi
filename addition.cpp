#include <bits/stdc++.h>
#include "header.hpp"
using namespace std;

vector<int> addition(vector<int> &a, vector<int> &b, int precision, int base)
{
    int carry = 0;
    int i = 0, j = 0;
    vector<int> ans;
    while (i < a.size() && j < b.size())
    {
        if (a[i] + b[j] + carry >= base)
        {
            ans.push_back(a[i] + b[i] + carry - base);
            carry = 1;
        }
        else
        {
            ans.push_back(a[i] + b[i] + carry);
            carry = 0;
        }
        i ++; j++;
    }
    while (i < a.size())
    {
        if (a[i] + carry >= base)
        {
            ans.push_back(a[i] + carry - base);
            carry = 1;
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
        if (b[j] + carry >= base)
        {
            ans.push_back(b[j] + carry - base);
            carry = 1;
        }
        else
        {
            ans.push_back(b[j] + carry);
            carry = 0;
        }
        j++;
    }
    if (carry > 0)
    {
        ans.push_back(carry);
    }
    return ans;
}
