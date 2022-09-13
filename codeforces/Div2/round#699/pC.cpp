#include <bits/stdc++.h>
#define inf (int)1e18
// #define inf (int)1e9
// #define int long long
#define N 300010 
using namespace std;
typedef long long ll;

int a[N], b[N], c[N], ans[N];

vector<int> g[N];
int32_t main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for(int i = 0 ;i <= n; i++) g[i].clear();
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            if (a[i] != b[i]) g[b[i]].push_back(i);
        }
        for (int i = 0; i < m; i++) cin >> c[i];
        int last = -1;
        if ((int)g[c[m-1]].size() > 0)  {
            last = g[c[m-1]].back();
            g[c[m-1]].pop_back();
        }
        else {
            for (int i = 0; i < n; i++) {
                if (c[m-1] == b[i]) {
                    last = i;
                    break;
                }
            }
        }
        if (last == -1) {cout << "no\n";continue;}
        ans[m-1] = last;
        for (int i = 0; i < m-1; i++) {
            if ((int)g[c[i]].size() == 0) {
                ans[i] = last;
            }
            else {
                ans[i] = g[c[i]].back();
                g[c[i]].pop_back();
            }
        }
        int flag = 1;
        for (int i = 1; i <= n; i++) {
            if((int)g[i].size() > 0) flag = 0;
        }
        if(!flag) {cout << "no\n";continue;}
        cout << "yes\n";
        for (int i = 0; i < m; i++) {
            if (i) cout << " ";
            cout << ans[i]+1;
        }
        cout << "\n";
    }
}