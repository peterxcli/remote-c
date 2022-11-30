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
    if (n & 1) {
        for (int i = 0; i < n; i++) cout << "1 ";
        cout << endl;
    }
    else {
        // int sum = 0, pre = 0;
        // for (int i = 1; i < n-1; i++) {
        //     sum += i;
        //     pre ^= i;
        // }
        // int k = n-1;
        // int inf = INT_MAX * k;
        // for (int i = 0; i < n-1; i++) cout << k << " ";
        // cout << (k * inf - inf * (k+1)) / k;
        // cout << 1;
        for (int i = 0; i < n-2; i++) cout << "2 ";
        cout << "1 3";
        cout << endl;
    }

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