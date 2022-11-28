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
    if (n % 2 == 0) {
        for (int i = 0; i < n/2; i++) cout << i+n/2 << " ";
        for (int i = 1; i <= n/2; i++) cout << n/2 + i+n/2  << " ";
    }
    else {
        // for (int i = 0; i < n/2; i++) cout << 1 + i*2  << " ";
        // cout << 0 << " ";
        // for (int i = 1; i <= n/2; i++) cout << n + i*2  << " ";
        for (int i = 0; i < n/2; i++) cout << i+n/2 + 2 << " ";
        for (int i = 1; i <= n/2; i++) cout << n/2 + i +n/2 + 3 << " ";
        // cout << 1+n/2;
        cout << n/2+n+3;
    }
    cout << endl;
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