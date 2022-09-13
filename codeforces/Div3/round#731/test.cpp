#include <bits/stdc++.h>
#define icantcode            \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;
int t = 0;
string s;
bool can = 0;
int main() {
    icantcode
    cin >> t;
    while (t--) {
        can = 0;
        int idx = -1;
        cin >> s;
        if (s.length() == 1) {
            if (s[0] == 'a')
                cout << "yes\n";
            else
                cout << "no\n";
            continue;
        }
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a') {
                idx = i;
                break;
            }
        }
        int l = idx - 1, r = idx + 1;
        for (int i = 1; i < s.length(); i++) {
            int tmp = 97 + i;
            if (l >= 0 && s[l] == char(tmp)) {
                l--;
                can = 1;
            } 
            else if (r < s.length() && s[r] == char(tmp)) {
                r++;
                can = 1;
            } 
            else {
                can = 0;
                break;
            }
        }
        if (can)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}