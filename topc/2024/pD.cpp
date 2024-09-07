// #include<bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define ll long long

string s[102];
int n, m;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}, dxx[4] = {-1, 1, -1, 1}, dyy[4] = {1, 1, -1, -1};
ll mod = 1000000007;
bool ch(int x, int y) {
    return (x >= 0) && (x < n) && y >= 0 && y < m;
}
ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll gcd = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}
ll mod_inverse(ll a, ll m) {
    ll x, y;
    ll g = extended_gcd(a, m, x, y);
    return (x % m + m) % m;
}
int main() {
    int d0, d1, d2;
    cin >> n >> m >> d0 >> d1 >> d2;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vector<pair<int, int>> question_marks;
            ll current_ans = 0;
            if (s[i][j] == '?') {
                question_marks.push_back({i, j});
            }
            for (int e = 0; e < 4; e++) {
                int xx = i + dx[e], yy = j + dy[e];
                if (ch(xx, yy) && s[xx][yy] == '?') {
                    question_marks.push_back({xx, yy});
                }
            }
            for (int e = 0; e < 4; e++) {
                int xx = i + dxx[e], yy = j + dyy[e];
                if (ch(xx, yy) && s[xx][yy] == '?') {
                    question_marks.push_back({xx, yy});
                }
            }

            // enumerate all possible values for the question marks with bitmask
            for (int mask = 0; mask < (1 << question_marks.size()); mask++) {
                for (int q = 0; q < question_marks.size(); q++) {
                    int xx = question_marks[q].first, yy = question_marks[q].second;
                    if (mask & (1 << q)) {
                        s[xx][yy] = 'V';
                    } else {
                        s[xx][yy] = '.';
                    }
                }
                // calculate the current answer
                if (s[i][j] == 'V') {
                    current_ans = (current_ans + d0) % mod;
                }
                else if (s[i][j] == '.') {
                    ll max_day = 0;
                    for (int e = 0; e < 4; e++) {
                        int xx = i + dx[e], yy = j + dy[e];
                        if (ch(xx, yy) && s[xx][yy] == 'V') {
                            // current_ans = (current_ans + d1) % mod;
                            max_day = max(max_day, (ll)d1);
                        }
                    }
                    for (int e = 0; e < 4; e++) {
                        int xx = i + dxx[e], yy = j + dyy[e];
                        if (ch(xx, yy) && s[xx][yy] == 'V') {
                            // current_ans = (current_ans + d2) % mod;
                            max_day = max(max_day, (ll)d2);
                        }
                    }
                    current_ans = (current_ans + max_day) % mod;
                }

                // reset the question marks
                for (int q = 0; q < question_marks.size(); q++) {
                    int xx = question_marks[q].first, yy = question_marks[q].second;
                    s[xx][yy] = '?';
                }
            }

            // update the answer
            current_ans = (current_ans * mod_inverse(1 << question_marks.size(), mod)) % mod;
            ans = (ans + current_ans) % mod;
        }
    }
    cout << ans << "\n";
}