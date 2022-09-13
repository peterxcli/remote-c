#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long

#define MAXN 5000005

int prime[MAXN], least[MAXN];

void fprime() {
    for (int i = 0; i <= MAXN; i++) prime[i] = 1;
    prime[2] = 1;
    for (int i = 2; i <= MAXN; i++) {
        if (prime[i] == false) continue; 
        for (int j = 2; j * i <= MAXN; j++) {
            prime[i*j] = 0;
            if (least[i*j] == 0) least[i*j] = i;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fprime();
    int Q;
    cin >> Q;
    while (Q--) {
        int N;
        cin >> N;
        map<int, int> mp;
        while (prime[N] != 1) {
            mp[least[N]]++;
            N /= least[N];
        }
        mp[N]++;
        int ans = 0;
        for (auto x : mp) {
            int a = x.first, b = x.second;
            int tmp = 0;
            for (int i = 30; i >= 0; i--) {
                // if (b >= i) tmp += a * 
            }
        }
        cout << ans << "\n";
    }
    return 0;
}