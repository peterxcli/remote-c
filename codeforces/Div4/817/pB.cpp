// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    int n;
    cin >> n;
    string str1, str2;
    cin >> str1 >> str2;
    for (int i = 0; i < n; i++) { // "G", "B" trans to "G"
        if (str1[i] == 'G' || str1[i] == 'B') str1[i] = 'G';
        if (str2[i] == 'G' || str2[i] == 'B') str2[i] = 'G';
    }
    if (str1 == str2) cout << "yes\n";
    else cout << "no\n";
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