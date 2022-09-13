#include <bits/stdc++.h>
#define inf (int)1e18
// #define inf (int)1e9
#define int long long 
using namespace std;
typedef long long ll;

int32_t main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    // slove();
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> h(n, 0), Max(n, 0);
        for (int i = 0; i < n; i++) cin >> h[i];
        if (n == 1) {
            cout << "-1\n";
            continue;
        }
        int ans = 0;
        while (1) {
            int flag = 1, pos;
            for (int j = 0; j < n-1; j++) {
                if (h[j] < h[j+1]) {
                    flag = 0;
                    ans ++;
                    h[j] ++;
                    if (ans >= k) {
                        pos = j;
                    }
                    break;
                }
                // for (int i = 0; i < n; i++) cout << h[i] << " ";////////////
                // cout << "\n";//////////////////////////////////////////////
            }
            if (ans >= k) {
                cout << pos+1 << "\n";
                break;
            }
            if (flag) {
                cout << "-1\n";
                break;
            }
        }
    }
}

void slove() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    // slove();
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> h(n, 0);
        for (int i = 0; i < n; i++) cin >> h[i];
        if (n == 1) {
            cout << "1\n";
            continue;
        }
        int ans = 0, flag = 1; 
        for (int i = n-1; i >= 1; i--) {
            if (h[i] > h[i-1]) {
                ans += h[i]-h[i-1];
                h[i-1] = h[i];
                if (ans >= k) {
                    cout << i << "\n";
                    flag = 0;
                    break;
                }
            } 
        }
        if (flag) cout << "-1\n";
    }
}