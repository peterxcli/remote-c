#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int N;
    cin >> N;
    N *= 2;
    int ans = 0;
    for (int i = 1; i*i <= N; i++) {
        int c = i, d = N/i; 
        if (N % i == 0 && (d+1-i) % 2 == 0) 
            ans ++;
        if (N % i == 0 && (c+1-d) % 2 == 0) 
            ans ++;
    }
    // for (int i = 1; i*i <= N; i++) {
    //     if (N % i == 0 && (N/i)+1-i % 2 == 0) {
    //         ans += 2;
    //     }
    // }
    cout << ans << "\n";
}