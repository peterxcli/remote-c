// #pragma G++ optimize(2, "Ofast", "inline")
// #include <bits/stdc++.h>
// // #define inf (int)1e18
// // #define inf (int)1e9
// #define int long long
// using namespace std;
// typedef long long ll;

// void solve() {
//     int x, flag = 0;
//     cin >> x;
//     if (x == 2) flag = 1; 
//     for (int i = 2; i*i <= x; i++) {
//         if (x % i == 0) {
//             int j = x/i;
//             if ((i*i - j) % 3 == 0 && (i*i - j) >= 0) flag = 1;
//             // if ((j*j - i) % 3 == 0 && (j*j - i) >= 0) flag = 1;
//         }
//     }
//     if (flag) cout << "yes\n";
//     else cout << "no\n";
// }

// int32_t main() {
//     cin.tie(0), ios_base::sync_with_stdio(0);   
//     int t;
//     cin >> t;
//     while(t--) {
//         solve();
//     }
//     // solve();
// }

#pragma G++ optimize(2, "Ofast", "inline")
#include <bits/stdc++.h>
// #define inf (int)1e18
// #define inf (int)1e9
#define int long long
using namespace std;
typedef long long ll;

void solve() {
    int x, flag = 0;
    cin >> x;
    for (int i = 1; i*i*i <= x; i++) {
        int j = floor(pow((double)(x - i*i*i), 1.0/3));
        // cout << i << " " << j << "\n";
        for (int k = j-10; k <= j+10; k++) {
            if (k <= 0) continue;
            if (i*i*i + k*k*k == x) flag = 1;
        }
    }
    if (flag) cout << "yes\n";//a^3+b^3 = (a+b)(a^2+b^2-ab)對巴?
    else cout << "no\n";
}

int32_t main() {
    cin.tie(0), ios_base::sync_with_stdio(0);   
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    // solve();
}