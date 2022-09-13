#include <bits/stdc++.h>
#define inf (int)1e18
// #define inf (int)1e9
// #define int long long
using namespace std;
typedef long long ll;

void slove() {
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if ((i&1) == 0) {
            if (str[i] == 'a') str[i] = 'b';
            else str[i] = 'a';
        }
        else {
            if (str[i] == 'z') str[i] = 'y';
            else str[i] = 'z';
        }
    }
    cout << str << "\n";
}

int32_t main() {
    cin.tie(0), ios_base::sync_with_stdio(0);   
    int t;
    cin >> t;
    while(t--) {
        slove();
    }
}