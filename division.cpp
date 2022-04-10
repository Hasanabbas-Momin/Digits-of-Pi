#include <bits/stdc++.h>
#include "header.hpp"
using namespace std;

pair<vector<int>, int> division(vector<int> &a, int a_point, vector<int> &b, int b_point, int precision, int base)
{
    // cout << "in division \n";
    vector<int> c;
    int temp;
    int c_point = 0;
    if (!(a_point > precision + b.size() + 3))
    {
        for (int i = 0; i < precision + b.size() - a_point + 3; i++)
        {
            c.push_back(0);
            c_point++;
        }
        temp = 0;
    }
    else
    {
        temp = precision + b.size() - a_point + 3;
        temp = -temp;
    }
    for (int i = temp; i < a.size(); i++)
    {
        c.push_back(a[i]);
        if (i < a_point)
            c_point++;
    }
    vector<int> d, q, r;
    int q_point;
    int d_point;
    int flag = 0;
    for (flag = b.size() - 1; b[flag] == 0; flag--)
        ;
    for (; flag >= 0; flag--)
    {
        d.push_back(b[flag]);
    }
    reverse(d.begin(), d.end());
    d_point = b_point;

    if (c.size() < d.size())
    {
        q.push_back(0);
        return make_pair(q, 0);
    }
    for (int i = 0; i < c.size(); i++)
    {
        r.push_back(c[i]);
    }
    r.push_back(0);

    for (int i = 0; i <= c.size() - d.size(); i++)
    {
        q.push_back(0);
    }
    for (int i = c.size() - d.size(); i >= 0; i--)
    {
        q[i] = ((r[i + d.size()] * base + r[i + d.size() - 1]) / d[d.size() - 1]);
        if (q[i] >= base)
            q[i] = base - 1;
        int carry = 0;
        for (int j = 0; j < d.size(); j++)
        {
            temp = r[i + j] - q[i] * d[j] + carry;
            div_t quorem = div(temp, base);
            if (temp < 0)
            {
                if (quorem.rem != 0)
                {
                    r[i + j] = base + quorem.rem;
                    carry = quorem.quot - 1;
                }
                else
                {
                    r[i + j] = quorem.rem;
                    carry = quorem.quot;
                }
            }
            else
            {
                r[i + j] = quorem.rem;
                carry = quorem.quot;
            }
        }
        r[i + d.size()] += carry;
        while (r[i + d.size()] < 0)
        {
            carry = 0;
            for (int j = 0; j < d.size(); j++)
            {
                temp = r[i + j] + d[j] + carry;
                div_t quorem = div(temp, base);
                if (temp < 0)
                {
                    if (quorem.rem != 0)
                    {
                        r[i + j] = base + quorem.rem;
                        carry = quorem.quot - 1;
                    }
                    else
                    {
                        r[i + j] = quorem.rem;
                        carry = quorem.quot;
                    }
                }
                else
                {
                    r[i + j] = quorem.rem;
                    carry = quorem.quot;
                }
            }
            r[i + d.size()] += carry;
            q[i]--;
        }
    }
    int last = q.size() - 1;
    while (q[last--] == 0 && last >= 0)
        q.pop_back();
    if (q.size() == 0)
        q.push_back(0);

    q_point = c_point - b_point;

    if (q[0] > base / 2)
        q[2]++;
    else if (q[0] == base / 2)
        if (q[1] > base / 2 || (q[1] == base / 2 && q[2] % 2))
            q[2]++;

    q[0] = 0;
    q[1] = 0;

    return make_pair(q, q_point);
}