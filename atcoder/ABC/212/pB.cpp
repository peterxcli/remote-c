#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
//#define int long long
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    string s;
    cin >> s;
    set<int> st;
    for (int i = 0; i < 4; i++) st.insert(s[i]-'0');
    int flag = 1;
    for (int i = 1; i < 4; i++) if (s[i] - '0' != (s[i-1] - '0' + 1) % 10) flag = 0;
    if (flag || st.size() == 1) cout << "Weak\n";
    else cout << "Strong\n";
    return 0;
}