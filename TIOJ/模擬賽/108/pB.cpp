#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long

char grid[3000][3000];

void divide(int x, int y, int l) {
    if (l == 1) return;
    l /= 3;
    for (int i = x - l/2; i <= x + l/2; i++) {
        for (int j = y - l/2; j <= y + l/2; j++) {
            grid[i][j] = '#';
        }
    }
    divide(x-l, y-l, l);
    divide(x, y-l, l);
    divide(x+l, y-l, l);
    divide(x-l, y, l);
    divide(x+l, y, l);
    divide(x-l, y+l, l);
    divide(x, y+l, l);
    divide(x+l, y+l, l);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int l = 1;
    for (int i = 1; i <= n; i++) l *= 3;
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= l; j++) {
            grid[i][j] = '.';
        }
    }
    divide((l+1) / 2, (l+1) / 2, l);
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= l; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
    return 0;
}