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
    int increase = 0, decrease = 0, c = 0;
    for (int i = 1; i <= n; i++) {
        int tmp; cin >> tmp;
        if (i != tmp) increase++;
        if (tmp != n - i + 1) decrease++;
        if (tmp != n - i + 1 && i != tmp) c++;
    }
    int tmp = min(increase, decrease);
    increase -= tmp;
    decrease -= tmp;
    //  cout << increase << " " << decrease <<  " " << c << "\n";
    if (decrease == max(increase, decrease) && decrease == c) cout << "First\n";
    else if (max(decrease, increase) <= c) cout << "Tie\n";
    else {
        increase += c+1;
        decrease += c;
        if (increase == decrease) cout << "Tie\n";
        else cout << (decrease < increase ? "Second\n" : "First\n");
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