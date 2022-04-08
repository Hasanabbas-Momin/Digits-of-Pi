#include <bits/stdc++.h>
#include "header.hpp"
using namespace std;

int main()
{
    srand(time(0));
    vector<int> *a = new vector<int>();
    vector<int> *b = new vector<int>();
    // for (int i = 0; i < 4; i++)
    // {
    //     int temp = rand() % 9;
    //     a->push_back(temp);
    //     temp = rand() % 9;
    //     if(i<2)
    //     b->push_back(temp);
    // }
    a->push_back(10000);
    b->push_back(2);
    for (int i = a->size() - 1; i >=0; i--)
    {
        cout << a->at(i) << " ";
    }
    cout << "\n";
    for (int i = b->size() - 1; i >=0; i--)
    {
        cout << b->at(i) << " ";
    }
    cout << "\n";
    vector<int> ans = addition(*a, *b, 0, 10);
    vector<int> ans2 = subtraction(ans, *b, 0, 10);
    vector<int> ans3 = multiplication(*a, *b, 0, 10);
    vector<int> *ans4 = new vector<int>();
    pair<vector<int>,vector<int>> hehe;
    hehe=division(*a, *b, 10,10 );
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    // cout << "\n";
    // for (int i = ans3.size()-1; i >= 0 ; i--)
    // {
    //     cout << ans3[i] << " ";
    // }
    cout << "\n";
    
    for (int i =hehe.first.size(); i >= 0 ; i--)
    {
        cout << hehe.first[i] << " ";
    }

    cout << "\n";
    for (int i =hehe.second.size(); i >= 0 ; i--)
    {
        cout << hehe.second[i] << " ";
    }
    // cout << INT_MAX;
}