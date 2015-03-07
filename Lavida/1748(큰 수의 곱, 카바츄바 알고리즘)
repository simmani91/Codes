//1748 큰 수의 곱, 카바츄바 알고리즘
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <map>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
 
vector<int> Normalize(vector<int>& ans){
    int n = ans.size();
    ans.push_back(0);
    for (int i = 0; i<n; i++) {
        if (ans[i]<0){
            int borrow = (abs(ans[i]) + 9) / 10;
            ans[i + 1] -= borrow;
            ans[i] += borrow * 10;
        }
        else{
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
    }
    if (ans.back() ==0) ans.pop_back();
    return ans;
}
 
vector<int> Multifly(vector<int>& a, vector<int>& b){
    int an = a.size(), bn = b.size();
    vector<int> ans(an + bn + 1, 0);
 
    //needs prejudgement
    for (int i = 0; i<an; i++)
    for (int j = 0; j<bn; j++)
        ans[i + j] += (a[i] * b[j]);
 
    return Normalize(ans);
}
void Sub_a_from_b(vector <int>& a, vector<int>& b){
    a.resize(max(a.size(), b.size()) + 1);
    for (int i = 0; i < b.size(); i++) a[i] -= b[i];
    Normalize(a);
}
void Add_a_to_b(vector <int>& a, vector<int>& b, int k){
    a.resize(max(a.size(), b.size() + k));
    for (int i = 0; i < b.size(); i++) a[i + k] += b[i];
    Normalize(a);
}
 
vector <int> Multifly_Kabatuba(vector <int>& a, vector<int>& b){
    int an = a.size(), bn = b.size();
 
    if (an < bn) return Multifly_Kabatuba(b, a);
    if (an == 0 || bn == 0) return vector<int>();
    if (an < 50) return Multifly(a, b);
 
    int half = an / 2;
 
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());
 
    vector<int> z2 = Multifly_Kabatuba(a1, b1);
    vector<int> z0 = Multifly_Kabatuba(a0, b0);
 
    Add_a_to_b(b0, b1, 0);
    Add_a_to_b(a0, a1, 0);
 
    vector<int> z1 = Multifly_Kabatuba(a0, b0);
    Sub_a_from_b(z1, z0);
    Sub_a_from_b(z1, z2);
 
    vector<int> ret;
    Add_a_to_b(ret, z0, 0);
    Add_a_to_b(ret, z1, half);
    Add_a_to_b(ret, z2, half + half);
 
    return ret;
}
string toString(vector<int> a) {
    string ret;
    while (a.size() > 1 && a.back() == 0) a.pop_back();
    for (int i = 0; i < a.size(); i++)
        ret += char('0' + a[a.size() - 1 - i]);
    return ret;
}
 
vector<int> fromString(const string& s) {
    vector<int> ret;
    for (int i = 0; i < s.size(); i++)
        ret.push_back(s[i] - '0');
    reverse(ret.begin(), ret.end());
    return ret;
}
 
int main() {
    vector<int> a, b, c;
    int num;
    cin >> num;
 
    while (num--){
        string input1, input2;
 
        cin >> input1 >> input2;
 
        a = fromString(input1);
        b = fromString(input2);
        c = Multifly_Kabatuba(a, b);
 
        string ans = toString(c);
        cout << ans << endl;
    }
    return 0;
}