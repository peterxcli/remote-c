//https://codeforces.com/contest/1478/problem/B
#include <bits/stdc++.h>
#define MAX 1000000000

using namespace std;

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
        int q, d, a;
        cin >> q >> d;
        for(int i = 0; i < q; i++) {
            cin >> a;
            bool yes = 0;
            if (a >= d*10) yes = 1;
            else {
                while (a > 0) {
                    if (a%d == 0) {yes = 1; break;}
                    else a -= 10;
                }
            }
            cout << (yes?"yes\n":"no\n");
        }
    }
}

