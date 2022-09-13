#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
//#define int long long
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int N;cin >> N;
    string str;
    cin >> str;
    int tmp = 0;
    for (; tmp < str.size(); tmp++) if (str[tmp] == '1') break;
    if (!(tmp & 1)) cout << "Takahashi\n";
    else cout << "Aoki\n";
    return 0;
}