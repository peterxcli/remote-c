//codeforces template
#define MANY_SUBTASK
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
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    // for (int l = 0; l < n; l++) {
    //     for (int r = l; r < n; r++) {
    //         set<int> s;
    //         s.clear();
    //         for (int i = l; i <= r; i++) s.insert(a[i]);
    //         cout << l << " " << r << " " << r - l - (int)s.size() << endl;
    //     }
    // }
    // cout << endl;
    cout << 1 << " " << n << endl;
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