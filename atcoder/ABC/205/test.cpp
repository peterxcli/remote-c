#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
//#define int long long

vector<int> B;
vector<int> dp;

void binary(int n) {
    B.clear();
    while(n > 0) {
        B.push_back(n%2);
        n /= 2;
    }
    reverse(B.begin(), B.end());
}
int main() {
    int n, m;
    cin >> n >> m;
    int num = n, ans = 1;
    binary(m);
    dp.clear();
    for (int i=0; i<B.size(); i++) {
        num = num *= num;;
        dp.push_back(num);
    }
    for (int i=0; i<B.size(); i++) {
        if (B[i]) ans *= dp[i];
    }

    cout << ans;
    return 0;
}
