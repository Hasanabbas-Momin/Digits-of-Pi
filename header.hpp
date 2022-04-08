#include <bits/stdc++.h>
using namespace std;
pair<vector<int>, int> addition(vector<int> &x,int x_point, vector<int> &y, int y_point, int precision, int base);
pair<vector<int>, int> subtraction(vector<int> &x, int x_point, vector<int> &y, int y_point, int precision, int base);
pair<vector<int>, int> multiplication(vector<int> &a, int a_point, vector<int> &b, int b_point, int precision, int base);
pair<vector<int>, int> division(vector<int> &a, int a_point, vector<int> &b, int b_point, int precision, int base);
void printvector(vector<int> &a);
pair<vector<int>, int> sqrt(vector<int> &a, int a_point, int precision, int base);
pair<vector<int>, int> pi(int precision, int base);
