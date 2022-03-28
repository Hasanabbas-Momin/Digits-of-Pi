#include <bits/stdc++.h>
#include "header.hpp"
using namespace std;

int main()
{
    vector<int> *a = new vector<int>();
    vector<int> *b = new vector<int>();
    for (int i = 0; i < 10; i++)
    {
        int temp = rand() % 255;
        a->push_back(temp);
        b->push_back(temp);
    }
    vector<int> ans = addition(*a, *b, 0, (int)pow(2, 16));
    vector<int> ans2 = subtraction(ans, *b, 0, (int)pow(2, 16));
    for (int i = 0; i < a->size(); i++)
    {
        cout << a->at(i) << " ";
    }
    cout << "\n";
    for (int i = 0; i < b->size(); i++)
    {
        cout << b->at(i) << " ";
    }
    cout << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < ans2.size(); i++)
    {
        cout << ans2[i] << " ";
    }
    cout << "\n";
    cout << INT_MAX;
}