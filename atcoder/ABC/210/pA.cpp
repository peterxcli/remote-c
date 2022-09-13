#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
//#define int long long
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    long long N, A, X, Y;
    cin >> N >> A >> X >> Y;
    cout << max(N-A, 0LL)*Y+min(A, N)*X << "\n";
    return 0;
}