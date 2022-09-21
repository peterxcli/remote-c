#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long

int n, B, C;
vector<int> h;

bool check(int m) {
    int sum = 0;
    for (int i = 0; i < n ; i++) {

    }
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l = 0, r = 0;
    cin >> n >> B >> C;
    h.resize(n);
    for (auto &x : h) {cin >> x; x /= B; r += x;}
    int k = C / B;
    // while (l < r) {
    //     int m = (l + r) / 2;
    //     if (check(m)) l = m;
    //     else r = m-1;
    // }
    // cout << l << "\n";
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    for (int i = 0; i < n; i++) pq.push({h[i], i});
    pq.push({*min_element(h.begin(), h.end()), min_element(h.begin(), h.end()) - h.begin()});
    int ans = 0;
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int idx = cur.second;
        if (cur.second == 0) {
            if (h[1] - h[idx] > k) {
                ans += (h[1] - h[idx] - k);
                h[1] = h[idx] + k;
                pq.push({h[1], 1});
            }
        }
        else if (cur.second == n-1) {
            if (h[n-2] - h[idx] > k) {
                ans += (h[n-2] - h[idx] - k);
                h[n-2] = h[idx] + k;
                pq.push({h[n-2], n-2});
            }
        }
        else {
            if (h[idx+1] - h[idx] > k) {
                ans += (h[idx+1] - h[idx] - k);
                h[idx+1] = h[idx] + k;
                pq.push({h[idx+1], idx+1});
            }
            if (h[idx-1] - h[idx] > k) {
                ans += (h[idx-1] - h[idx] - k);
                h[idx-1] = h[idx] + k;
                pq.push({h[idx-1], idx-1});
            }
        }
    }
    cout << ans << "\n";
    return 0;
}