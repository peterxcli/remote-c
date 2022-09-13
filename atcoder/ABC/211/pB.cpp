#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
//#define int long long
int main() {
    string x[4] = {"H", "2B", "3B", "HR"};
    set<string> st;
    for (int i = 0; i < 4; i++) st.insert(x[i]);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    string s;
    map<string, int> mp;
    for (int i = 0; i < 4; i++) {
        cin >> s;
        if (st.find(s) != st.end()) {
            mp[s]++;
        }
    }
    int flag = 1;
    for (auto i : mp) if (i.second != 1) flag = 0;
    if (flag && mp.size() == 4) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}