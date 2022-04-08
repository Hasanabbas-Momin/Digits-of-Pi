#include <bits/stdc++.h>
#include "header.hpp"
using namespace std;

// pair<vector<int>, vector<int>> division(vector<int> &a, vector<int> &b, int precision, int base)
// {
//     vector<int> r;
//     vector<int> q;
//     int carry = 0;
//     int temp;
//     while (b.size() != 0 && b[b.size() - 1] == 0)
//     {
//         b.pop_back();
//     }
//     int x = a.size() - b.size();
//     for (int i = 0; i < x; i++)
//         q.push_back(0);
//     for (int i = 0; i < a.size(); i++)
//     {
//         r.push_back(a[i]);
//     }
//     r.push_back(0);
//     for (int i = a.size() - b.size(); i >= 0; i--)
//     {
//         q.push_back((r[i + b.size()] * base + r[i + b.size() - 1]) / b[b.size() - 1]);
//         if (q[i] >= base)
//             q[i] = base - 1;
//         carry = 0;
//         for (int j = 0; j < b.size(); j++)
//         {
//             temp = r[i + j] - (q[i] * b[j]) + carry;
//             carry = temp / base;
//             r[i + j] = temp % base;
//             if (r[i + j] < 0)
//             {
//                 carry--;
//                 r[i + j] += base;
//             }
//         }
//         r[i + b.size()] += carry;
//         while (r[i + b.size()] < 0)
//         {
//             carry = 0;
//             for (int j = 0; j < b.size(); j++)
//             {
//                 temp = r[i + j] + b[j] + carry;
//                 carry = temp / base;
//                 r[i + j] = temp % base;
//                 if (r[i + j] < 0)
//                 {
//                     carry--;
//                     r[i + j] += base;
//                 }
//             }
//             r[i + b.size()] += carry;
//             q[i] -= 1;
//         }
//     }
//     // printvector(&r);

//     // while(q.size() != 0 && q[q.size()-1] == 0)
//     // {
//     //     q.pop_back();
//     // }
//     // while(r.size() != 0 && r[r.size()-1] == 0)
//     // {
//     //     r.pop_back();
//     // }
//     for (int i = 0; i < r.size(); ++i)
//     {
//         cout << "r => " << r[i] << " ";
//     }
//     cout << "\n";

//     // if (precision >= q.size())
//     // {
//     //     r.insert(r.begin(),0);
//     //     // vector<int> *q1 = new vector <int> ();
//     //     division(r, b, precision, base, q);
//     // //     q.insert(q.begin(), q1->begin(), q1->end());
//     // }
//     return make_pair(q, r);
// }

// vector<int> decimal_after_division(vector<int>rem,vector<int>divisor)
// {
//     vector <int> Base1;
//     vector <int> decimal;
//     vector<int> remBase;
//     vector <int> quotient;
//     vector<int> remainder = rem;
//     int j;

//     Base1.push_back(0);Base1.push_back(1);
//      for(int i=0;i<30;i++)
//      {
//            remBase = multiplication(Base1,remainder, 10, 10);
//     //     //for(int i=0;i<remBase.size();i++)
//     //     //     cout<<remBase[i]<<" ";
//     //     // cout<<endl;
//            quotient = division(remBase,divisor, 10, 10).first;
//            if(quotient.size()==0) decimal.push_back(0);
//            else decimal.push_back(quotient[0]);
//            remainder = division(remBase,divisor, 10, 10).second;
//            for(j=0;j<remainder.size();j++)
//            {
//                if(remainder[j]!=0) break;
//            }
//            if(j==remainder.size()) return decimal;
//      }
//     return decimal;

// }

// pair<vector<int>,vector<int>> Div_with_dec(vector<int> number1,vector<int>dec1,vector<int> number2,vector<int>dec2)
// {
//     vector <int> expanded_num1,expanded_num2,num,dec,quo,rem,decimal;

//     for(int i=dec1.size()-1;i>=0;i--)
//     {
//         expanded_num1.push_back(dec1[i]);
//     }
//     for(int i=0;i<number1.size();i++)
//     {
//         expanded_num1.push_back(number1[i]);
//     }

//     for(int i=dec2.size()-1;i>=0;i--)
//     {
//         expanded_num2.push_back(dec2[i]);
//     }
//     for(int i=0;i<number2.size();i++)
//     {
//         expanded_num2.push_back(number2[i]);
//     }

//     //int power_num1 = -1*dec1.size();
//     //int power_num2 = -1*dec2.size();

//     quo = division(expanded_num1,expanded_num2, 10, 10).first;
//     rem = division(expanded_num1,expanded_num2, 10, 10).second;

//     decimal = decimal_after_division(rem,expanded_num2);
//     //for(int i=0;i<decimal.size();i++) cout<<decimal[i]<<" ";
//     if(dec1.size()<dec2.size())
//     {
//         for(int i=dec2.size()-dec1.size()-1;i>=0;i--)
//         {
//             num.push_back(decimal[i]);
//         }
//         for(int i=0;i<quo.size();i++)
//         {
//             num.push_back(quo[i]);
//         }
//         for(int i=dec2.size()-dec1.size();i<decimal.size();i++)
//         {
//             dec.push_back(decimal[i]);
//         }
//     }
//     else
//     {
//         for(int i=dec1.size()-dec2.size();i<quo.size();i++)
//         {
//             num.push_back(quo[i]);
//         }
//         for(int i=dec1.size()-dec2.size()-1;i>=0;i--)
//         {
//             dec.push_back(quo[i]);
//         }
//         for(int i=0;i<decimal.size();i++)
//         {
//             dec.push_back(decimal[i]);
//         }
//     }

//     vector<int> n1;
//     vector<int> d1;
//     int x=0,y=0;
//     int p = num.size();
//     int q = dec.size();
//     for(int i=p-1;i>=0;i--)
//     {
//         if(num[i]>0)
//         {
//             x=i+1;
//             break;
//         }
//     }
//     for(int i=0;i<x;i++)
//     {
//         n1.push_back(num[i]);
//     }

//     for(int i=q-1;i>=0;i--)
//     {
//         if(dec[i]>0)
//         {
//             y=i+1;
//             break;
//         }
//     }
//     for(int i=0;i<y;i++)
//     {
//         d1.push_back(dec[i]);
//     }

//     return make_pair(n1,d1);

// }

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