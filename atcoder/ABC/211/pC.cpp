#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;

int cac(string X, string Y, int m, int n) {
    int T[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        T[i][0] = 1;
    }
    for (int j = 1; j <= n; j++) {
        T[0][j] = 0;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) T[i][j] = (T[i - 1][j - 1] + T[i - 1][j]) % mod;
            else T[i][j] = T[i - 1][j] % mod;
        }
    }
    return T[m][n];
}

int32_t main() {
    string X;
    string Y = "chokudai";
    cin >> X;
    cout << cac(X, Y, X.size(), Y.size()) << "\n";
    return 0;
}