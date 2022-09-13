#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
//#define int long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int A, B, C;
    cin >> A >> B >> C;
    if (C & 1) {
        if (A == B) cout << "=\n";
        else if (A > B) cout << ">\n";
        else cout << "<\n";
    }
    else {
        if (abs(A) == abs(B)) cout << "=\n";
        else if (abs(A) > abs(B)) cout << ">\n";
        else cout << "<\n";
    }
}