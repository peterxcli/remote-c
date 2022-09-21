//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

int f(int x) {
    int ret = 0;
    while (x) {
        x /= 10;
        ret++;
    }
    return ret;
}

void solve_subtask() {
    priority_queue<int> a, b;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        a.push(tmp);
    }
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        b.push(tmp);
    }
    //cout << a.size() << " " << b.size() << "\n";
    int ans = 0;
    while (!b.empty()) {
        if (b.top() == a.top()) {
            a.pop(); b.pop();
        }
        else if (a.top() > b.top()) {
            int tmp = a.top();
            a.push(to_string(tmp).size());
            a.pop();
            ans++;
        }
        else {
            int tmp = b.top();
            b.push(to_string(tmp).size());
            b.pop();
            ans++;
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