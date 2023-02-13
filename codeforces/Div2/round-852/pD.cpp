//codeforces template
// #define MANY_SUBTASK
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void debug_out(){cerr<<"]\n"<<flush;}
template<typename Head,typename... Tail>void debug_out(Head H,Tail... T){cerr << H;if(sizeof...(T))cerr<<", ";debug_out(T...);}
#define debug(...) cerr<<"LINE("<<__LINE__<<") : ["<<#__VA_ARGS__<<"] = [";debug_out(__VA_ARGS__)
void solve_subtask() {
    int n;
    cin >> n;
    vector<int> pos_a(n+1), pos_b(n+1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pos_a[x] = i+1;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pos_b[x] = i+1;
    }
    int la = n, ra = 1, lb = n, rb = 1, ans = 1;
    for (int i = 1; i < n; i++) {
        la = min(la, pos_a[i]);
        ra = max(ra, pos_a[i]);
        lb = min(lb, pos_b[i]);
        rb = max(rb, pos_b[i]);
        int min_la, max_ra, min_lb, max_rb;
        if (pos_a[i+1] < la) {
            min_la = pos_a[i+1] + 1;
            max_ra = n;
        }
        else {
            min_la = 1;
            max_ra = pos_a[i+1] - 1;
        }

        if (pos_b[i+1] < lb) {
            min_lb = pos_b[i+1] + 1;
            max_rb = n;
        }
        else {
            min_lb = 1;
            max_rb = pos_b[i+1] - 1;
        }
        ans += max(0LL, min(la, lb) - max(min_la, min_lb) + 1) * max(0LL, min(max_ra, max_rb) - max(ra, rb) + 1); 
    }
    ans += min(pos_a[1], pos_b[1]) * (min(pos_a[1], pos_b[1]) - 1) / 2;
    ans += (n - max(pos_a[1], pos_b[1])) * (n - max(pos_a[1], pos_b[1]) + 1) / 2;
    ans += abs(pos_a[1] - pos_b[1]) * (abs(pos_a[1] - pos_b[1]) - 1) / 2;
    cout << ans << endl;
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