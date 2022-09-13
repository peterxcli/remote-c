#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
//#define int long long
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    if (b < a) cout << "0\n";
    else cout << b-a+1 << "\n";
    return 0;
}