#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
// #define int long long
vector<int> A, B;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    A.resize(N), B.resize(M);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    int ans = INT32_MAX;
    set<int> st;
    for (auto x : B) st.insert(x);
    for (auto x : A) {
        if (st.find(x) != st.end()) {
            ans = 0;
            break;
        }
        else {
            auto idx = st.insert(x).first;
            if (idx == st.begin()) ans = min(ans, abs(*next(idx) - x));
            if (idx == prev(st.end())) ans = min(ans,  abs(*prev(idx) - x));
            else ans = min(ans, min(abs(*prev(idx) - x), abs(*next(idx) - x)));
            st.erase(x);
        }
    }
    cout << ans << "\n";
    return 0;
}