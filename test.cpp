#include <bits/stdc++.h>
#include "header.hpp"
using namespace std;

int main()
{
    srand(time(0));
    vector<int> *a = new vector<int>();
    vector<int> *b = new vector<int>();
    for (int i = 0; i < 2; i++)
    {
        int temp = rand() % 9;
        a->push_back(temp);
        b->push_back(temp);
    }
    vector<int> ans = addition(*a, *b, 0, 10);
    vector<int> ans2 = subtraction(ans, *b, 0, 10);
    vector<int> ans3 = multiplication(*a, *b, 0, 10);
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
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    cout << "\n";
    for (int i = 0; i < ans3.size(); i++)
    {
        cout << ans3[i] << " ";
    }
    cout << "\n";
    // cout << INT_MAX;
}