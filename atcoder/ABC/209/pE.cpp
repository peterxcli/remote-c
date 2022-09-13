#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
//#define int long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> s(n);
    for (auto &x : s) cin >> x;
    map<string, vector<int>> prefix;
    for (int i = 0; i < s.size(); i++) {
        prefix[s[i].substr(0, 3)].emplace_back(i);
    }
    for (int i = 0; i < s.size(); i++) {
        prefix[s[i].substr(0, 3)].emplace_back(i);
    }
    return 0;
}