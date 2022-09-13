#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
//#define int long long
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int A, B;
    cin >> A >> B;
    if (A && B == 0) cout << "Gold\n";
    else if (A == 0 && B) cout << "Silver\n";
    else cout << "Alloy\n";
    return 0;
}