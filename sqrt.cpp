#include <bits/stdc++.h>
#include "header.hpp"
using namespace std;

pair<vector<int>, int> sqrt(vector<int> &a, int a_point, int precision, int base)
{
    // cout << "in sqrt \n";
    pair<vector<int>, int> ans, b;
    ans.second = 1;
    ans.first.push_back(5);
    ans.first.push_back(1);
    int i = 1;
    b.second = 0;
    b.first.push_back(2);
    while (i >> 1 <= precision)
    {
        pair<vector<int>, int> temp = division(a, a_point, ans.first, ans.second, precision, base);
        pair<vector<int>, int> temp2 = addition(ans.first, ans.second, temp.first, temp.second, precision, base);
        ans = division(temp2.first, temp2.second, b.first, b.second, precision, base);
        i = i << 1;
    }
    return ans;
}