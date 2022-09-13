//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    int n;
    cin >> n;
    pair<int, int> a, b;
    a.first = b.first = a.second = b.second = 0;
    int ans = 0, tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp == 1) {
            ans++;
            if (a.first-a.second > b.first-b.second) {
                b.first++;
            }
            else {
                a.first++;
            }
        }
        else if (tmp == 2) {
            if (a.first-a.second > b.first-b.second) {
                a.second++;
            }
            else {
                b.second++;
            }
        }
        else {
            if (a.first+1 > a.second) a.first++, ans++;
            else if (b.first+1 > b.second) b.first++, ans++;
            else if (a.first-a.second > b.first-b.second) {
                a.second++;
            }
            else {
                b.second++;
            }
        }   
    }
    cout << ans << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 1;
#ifdef MANY_SUBTASK
    cin >> cnt;
#endif
    while (cnt--)
    {
        solve_subtask();
    }
    return 0;
}