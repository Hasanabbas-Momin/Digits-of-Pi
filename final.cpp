#include <bits/stdc++.h>
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
        i++;
        j++;
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
    return make_pair(ans, ans_point);
}

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
    int c_point = (a_point + b_point);
    return make_pair(c, c_point);
}

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