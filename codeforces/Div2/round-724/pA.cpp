//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[0] < 0) cout << "no\n";
    else {
        cout << "yes\n";
        cout << a[N-1]+1 << "\n";
        for (int i = 0; i <= a[N-1]; i++) cout << i << (i != a[N-1]?" ":"\n");
    }
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