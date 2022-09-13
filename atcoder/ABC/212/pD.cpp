#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    vector<int> A(N), B(M);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    int ans = LLONG_MAX;
    // sort(A.begin(), A.end());
    // sort(B.begin(), B.end());
    set<int> st;
    for (auto x : B) st.insert(x);
    for (auto x : A) {
        if (st.find(x) != st.end()) ans = 0;
        else {
            auto idx = st.insert(x).first;
            if (idx == st.begin()) ans = min(ans, abs(*next(idx) - x));
            if (idx == prev(st.end())) ans = min(ans,  abs(*prev(idx) - x));
            else ans = min(ans, min(abs(*prev(idx) - x), abs(*next(idx) - x)));
        }
    }
    cout << ans << "\n";
    return 0;
}