#include <bits/stdc++.h>
#include "header.hpp"
using namespace std;

pair<vector<int>, int> pi(int precision, int base)
{
    // cout << "in pi \n";
    pair<vector<int>, int> an, bn, pn, an1, bn1, pn1, two, one;
    two.second = 0;
    two.first.push_back(2);
    an = sqrt(two.first, two.second, precision, base);
    bn.second = 0;
    bn.first.push_back(0);
    pn = addition(two.first, two.second, an.first, an.second, precision, base);
    one.second = 0;
    one.first.push_back(1);
    unsigned long long c = 1;
    while (c >> 1 < precision)
    {
        c = c << 1;
        pair<vector<int>, int> sqrt_an = sqrt(an.first, an.second, precision, base);
        pair<vector<int>, int> temp1 = division(one.first, one.second, sqrt_an.first, sqrt_an.second, precision, base);
        pair<vector<int>, int> temp2 = addition(sqrt_an.first, sqrt_an.second, temp1.first, temp1.second, precision, base);
        an1 = division(temp2.first, temp2.second, two.first, two.second, precision, base);
        
        temp1 = addition(one.first, one.second, bn.first,bn.second, precision, base);
        temp2 = multiplication(temp1.first, temp1.second, sqrt_an.first, sqrt_an.second, precision, base);
        pair<vector<int>, int> temp3 = addition(an.first, an.second, bn.first, bn.second, precision, base);
        bn1 = division(temp2.first, temp2.second, temp3.first, temp3.second, precision, base);

        temp1 = addition(one.first, one.second, an1.first, an1.second, precision, base);
        temp2 = multiplication(temp1.first, temp1.second, pn.first, pn.second, precision, base);
        temp3 = multiplication(temp2.first, temp2.second, bn1.first, bn1.second, precision, base);
        temp1 = addition(one.first, one.second, bn1.first, bn1.second, precision, base);
        pn1 = division(temp3.first, temp3.second, temp1.first, temp1.second, precision, base);
        an = an1;
        bn = bn1;
        pn = pn1;
    }
    return pn;
}