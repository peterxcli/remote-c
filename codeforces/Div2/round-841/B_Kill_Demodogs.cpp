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
const int mod = 1e9+7;
void solve_subtask() {
    int n;
    cin >> n;
    int ans = 0;
    ans = (n * (n+1)) % mod;
    ans = ans * (2*n+1) % mod;
    ans = ans * 166666668 % mod;
    ans *= 2;
    ans %= mod;
    ans -= (n*(n+1) / 2LL) % mod;
    ans = (ans + mod*mod) % mod;
    // cout << ans << " " <<  ans * 2022 % mod << "\n";
    cout << (2022) * ans % mod << "\n";
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
