#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (auto& x : A) cin >> x;
    vector<int> low(N);
    for (int i = 0; i < N; ++i) low[i] = A[i] - (i + 1);
    while (Q--) {
        int K;
        cin >> K;
        int idx = lower_bound(low.begin(), low.end(), K) - low.begin();
        if (idx == N) cout << A[N - 1] + (K - low[N - 1]) << '\n';
        else cout << A[idx] - (low[idx] - K + 1) << '\n';
    }
}