#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
//#define int long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    list<int> lst[60];
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        lst[tmp].push_back(i);
    }
    for (int i = 1; i <= q; i++) {
        int tmp;
        cin >> tmp;
        cout << lst[tmp].front() << " ";
        lst[tmp].pop_front();
        lst[tmp].push_back(n);
    }
    cout << "\n";
    return 0;
}