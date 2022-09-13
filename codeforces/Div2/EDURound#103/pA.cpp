//https://codeforces.com/contest/1476/problem/0
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (k < n) {
            if (n % k == 0) k = n;
            else k *= (n/k)+1;
        }
        if (k % n == 0) {
            cout << k / n << "\n";
        }
        else {
            cout << (k / n)+1 << "\n";
        }
    }
}