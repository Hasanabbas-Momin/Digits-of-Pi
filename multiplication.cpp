#include <bits/stdc++.h>
#include "header.hpp"
using namespace std;

vector<int> multiplication(vector<int> &a, vector<int> &b, int precision, int base)
{
    vector<int> c;
    int  carry = 0;
    for(int i = 0; i<a.size()+b.size()-1; i++)
    {
        c.push_back(0);
    }
    for(int i = 0; i< a.size(); i++)
    {
        carry = 0;
        for(int j = 0; j < b.size(); j++)
        {
            int tmp = a[i]*b[j] + carry;
            carry = tmp / base;
            c[i+j] = tmp % base;
        }
    }
}