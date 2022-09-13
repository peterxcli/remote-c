#include <bits/stdc++.h>
#define inf (int)1e18
// #define inf (int)1e9
// #define int long long
using namespace std;
typedef long long ll;

void slove() {
    int n, k;
    cin >> n >> k;
    map<char,int> book1,book2;  
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < n; i++) {
        book1[a[i]]++;
        book2[b[i]]++;
    }
    int cnt = 0, flag = 1;
    for (char i = 'a'; i <= 'z'; i++) {
        if (book1[i] == book2[i]) continue;
        if (book1[i] > book2[i]) {
            cnt += book1[i]-book2[i];
        }
        else {
            int tmp = book2[i] - book1[i];
            if (cnt < tmp || tmp % k != 0) {
                flag = false;
                break;
            }
            cnt -= tmp;
        }
        if(cnt % k != 0) {
            flag = false;
            break;
        }
    }
    if (flag) cout << "yes\n";
    else cout << "no\n";
}

int32_t main() {
    cin.tie(0), ios_base::sync_with_stdio(0);   
    int t;
    cin >> t;
    while(t--) {
        slove();
    }
}