//codeforces template
//https://www.youtube.com/watch?v=RfDMpgThK4I
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
    int n, x;
    cin >> n >> x;
    //1 2 3 4 5 6 7 8 9
    //7 2 3 4 5 6   8 1
    //1 2 3 4 5
    //4       1
    // if (n % x)  
    if (n % x) {
        cout << -1 << "\n";
        return;
    }
    vector<int> p(n+1);
    for (int i = 1; i <= n; i++) {
        if (i == 1) p[i] = x;
        else if (i == n) p[i] = 1;
        else if (i == x) p[i] = n;
        else p[i] = i;
    }
    // for (int i = x+1; i <= n; i++) {
    //     if ()
    // }
    int idx = x+1, cur = x;
    while (idx < n) {
        for (int i  = idx; i < n; i++) {
            if (p[i] % cur == 0 && n % i == 0) {
                swap(p[i], p[cur]);
                idx = i+1;
                cur = i;
                break;
            }
            else if (i == n-1) idx = n;
        }
    }
    for (int i = 1; i <= n; i++) cout << p[i] << (i == n ? "\n" : " ");
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