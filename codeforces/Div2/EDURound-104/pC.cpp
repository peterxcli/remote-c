#include <bits/stdc++.h>
#define inf (int)1e18
// #define inf (int)1e9
#define int long long
using namespace std;
typedef long long ll;

void slove() {
    int n;
    cin >> n;
    vector<int> ans, score;
    if (n % 2 == 1) {
        for (int i = 1; i <= n*(n-1)/2; i++) {
            if(i & 1) cout << 1 << " ";
            else cout << -1 << " ";
        }
        cout << "\n";
        return;
    }
    int tmp = 0;
    while (n--) {
        tmp++;
        for (int i = 1; i <= n; i++) {
            if ((i==1) && (tmp&1)) cout << "0 ";
            else {
                if (!(i&1)) cout << "1 ";
                else cout << "-1 ";
            }

        }
    }
    cout << "\n";
}

int32_t main() {
    cin.tie(0), ios_base::sync_with_stdio(0);   
    int t;
    cin >> t;
    while(t--) {
        slove();
    }
}