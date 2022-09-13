#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> a(N+1);
    for (int i = 1; i <= N; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int flag = true;
    for (int i = 1; i <= N; i++) if (a[i] != i) flag = false;
    cout << (flag?"Yes\n":"No\n");
    return 0;
}