#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> a(N+1);
    for (int i = 0; i < N; i++) {
        cin >> a[i+1];
    }
    for (int i = 0; i < N; i++) {
        cout << a[i+1] - a[i] << " ";
    }
    cout << "\n";
    return 0;
}