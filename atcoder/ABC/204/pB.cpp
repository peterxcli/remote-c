#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
//#define int long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (tmp > 10) ans += (tmp-10);
    }
    cout << ans << "\n";
    return 0;
}