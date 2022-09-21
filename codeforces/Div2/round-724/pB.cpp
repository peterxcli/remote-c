//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int isSubstring(string &s1, string &s2) {
    int M = s1.length();
    int N = s2.length();
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;
        if (j == M)
            return true;
    }
    return 0;
}
void solve_subtask() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    for (char i = 'a'; i <= 'z'; i++) {
        string sub;
        sub.push_back(i);
        if(!isSubstring(sub, str)) {
            cout << sub << "\n";
            return;
        }
    }
    for (char i = 'a'; i <= 'z'; i++) {
        for (char j = 'a'; j <= 'z'; j++) {
            string sub;
            sub.push_back(i);sub.push_back(j);
            if(!isSubstring(sub, str)) {
                cout << sub << "\n";
                return;
            }
        }
    }
    for (char i = 'a'; i <= 'z'; i++) {
        for (char j = 'a'; j <= 'z'; j++) {
            for (char k = 'a'; k <= 'z'; k++) {
                string sub;
                sub.push_back(i);sub.push_back(j);sub.push_back(k);
                if(!isSubstring(sub, str)) {
                    cout << sub << "\n";
                    return;
                }
            }
            
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 1;
#ifdef MANY_SUBTASK
    cin >> cnt;
#endif
    while (cnt--) {
        solve_subtask();
    }
    return 0;
}