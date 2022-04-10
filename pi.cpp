#include <bits/stdc++.h>
#include "header.hpp"
using namespace std;

pair<vector<int>, int> pi(int precision, int base)
{
    pair<vector<int>, int> a, b, c, a1, b1, c1, two, one;
    two.second = 0;
    two.first.push_back(2);
    a = sqrt(two.first, two.second, precision, base);
    b.second = 0;
    b.first.push_back(0);
    c = addition(two.first, two.second, a.first, a.second, precision, base);
    one.second = 0;
    one.first.push_back(1);
    unsigned long long x = 1;
    while (x >> 1 < precision)
    {
        x = x << 1;
        pair<vector<int>, int> sqrt_a = sqrt(a.first, a.second, precision, base);
        pair<vector<int>, int> temp1 = division(one.first, one.second, sqrt_a.first, sqrt_a.second, precision, base);
        pair<vector<int>, int> temp2 = addition(sqrt_a.first, sqrt_a.second, temp1.first, temp1.second, precision, base);
        a1 = division(temp2.first, temp2.second, two.first, two.second, precision, base);
        
        temp1 = addition(one.first, one.second, b.first,b.second, precision, base);
        temp2 = multiplication(temp1.first, temp1.second, sqrt_a.first, sqrt_a.second, precision, base);
        pair<vector<int>, int> temp3 = addition(a.first, a.second, b.first, b.second, precision, base);
        b1 = division(temp2.first, temp2.second, temp3.first, temp3.second, precision, base);

        temp1 = addition(one.first, one.second, a1.first, a1.second, precision, base);
        temp2 = multiplication(temp1.first, temp1.second, c.first, c.second, precision, base);
        temp3 = multiplication(temp2.first, temp2.second, b1.first, b1.second, precision, base);
        temp1 = addition(one.first, one.second, b1.first, b1.second, precision, base);
        c1 = division(temp3.first, temp3.second, temp1.first, temp1.second, precision, base);
        a = a1;
        b = b1;
        c = c1;
    }
    return c;
}