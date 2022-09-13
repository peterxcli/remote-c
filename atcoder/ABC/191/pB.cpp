#include <bits/stdc++.h>
#define inf (int)1e18
// #define inf (int)1e9
// #define int long long
using namespace std;
typedef long long ll;

void slove() {
    int N, X, in;
    vector<int> out;
    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        cin >> in;
        if (in != X) out.push_back(in);
    }
    for (int i = 0; i < out.size(); i++) {
        if (i) cout << " ";
        cout << out[i];
    }
    cout << "\n";
}

int32_t main() {
    cin.tie(0), ios_base::sync_with_stdio(0);   
    // int t;
    // cin >> t;
    // while(t--) {
    //     slove();
    // }
    slove();
}