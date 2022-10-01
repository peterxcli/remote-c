// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    string str; cin >> str;
    vector<pair<int, int> > a(str.length());
    vector<int> b(str.length());
    for (int i = 0; i < a.size(); i++) {
        b[i] = a[i].first = str[i] - '0';
        a[i].second = i;
    }
    int mi = 9;
    for (int i = a.size()-1; i != -1; i--) {
        if (b[i] <= mi) {mi = b[i]; continue;}
        b[i] = min(b[i]+1LL, 9LL);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    // int cnt = 0;
    // for (int i = 0; i < a.size(); i++) if (i != a[i].second) cnt++;
    // cnt /= 2;
    // for (int i = a.size()-1; i >= 0 && cnt > 0; i--) {
    //     if (a[i].second == i) continue;
    //     a[i].first++, cnt--;
    // }
    for (int i = 0; i < a.size(); i++) cout << b[i];
    cout << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 1;
#ifdef MANY_SUBTASK
    cin >> cnt;
#endif
    while (cnt--) {
        solve_subtask();
    }
    return 0;
}