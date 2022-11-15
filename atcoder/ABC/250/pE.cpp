#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
void debug_out(){cerr<<"]\n"<<flush;}
template<typename Head,typename... Tail>void debug_out(Head H,Tail... T){cerr << H;if(sizeof...(T))cerr<<", ";debug_out(T...);}
#define debug(...) cerr<<"LINE("<<__LINE__<<") : ["<<#__VA_ARGS__<<"] = [";debug_out(__VA_ARGS__)
//#define endl '\n'
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937_64 rnd(std::chrono::system_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1);
    map<int, int> mp, pre;
    for (int i = 0; i < n; i++) cin >> a[i+1];
    for (int i = 0; i < n; i++) cin >> b[i+1];
    for (int i = 1; i <= n; i++) {
        if (!mp.count(a[i])) {mp[a[i]] = rnd()/1e6, pre[mp[a[i]]] = 1,  a[i] = a[i-1] + mp[a[i]];}
        else if (!pre.count(mp[a[i]])) {pre[mp[a[i]]] = 1; a[i] = a[i-1] + mp[a[i]];}
        else {a[i] = a[i-1];}
    }
    pre.clear();
    for (int i = 1; i <= n; i++) {
        if (!mp.count(b[i])) {mp[b[i]] = rnd()/1e6, pre[mp[b[i]]] = 1,  b[i] = b[i-1] + mp[b[i]];}
        else if (!pre.count(mp[b[i]])) {pre[mp[b[i]]] = 1; b[i] = b[i-1] + mp[b[i]];}
        else {b[i] = b[i-1];}
    }
    // for (int i = 0; i < n; i++) cout << a[i+1] << " ";
    // cout << "\n";
    // for (int i = 0; i < n; i++) cout << b[i+1] << " ";
    // cout << "\n";

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (a[x] == b[y]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}