#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, S, D, ans = 0;
    cin >> N >> S >> D;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        if (x < S && y > D) ans ++;
    }
    if (ans) cout << "Yes\n";
    else cout << "No\n";
}