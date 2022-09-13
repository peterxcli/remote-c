#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int dp[3005][3005]={0}, mark[3005][3005]={0};
string str1, str2, ans;
int str1_len, str2_len;

void search(int x, int y);

int main() {
    cin.tie(0), cin.sync_with_stdio(0), cout.tie(0);
    cin >> str1 >> str2;
    str1_len = str1.length(), str2_len = str2.length();
    for (int i = 1; i <= str1_len; i++) {
        for (int j = 1; j <= str2_len; j++) {
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                mark[i][j] = 1;
            }
            else if (dp[i-1][j] > dp[i][j-1]) {
                dp[i][j] = dp[i-1][j];
                mark[i][j] = 2;
            }
            else {
                dp[i][j] = dp[i][j-1];
                mark[i][j] = 3;
            }
        }
    }

    search(str2_len, str1_len);
    cout << ans << "\n";

    return 0;
}

void search(int x, int y) {
    if (x == 0 || y == 0)
        return;
    else if (mark[y][x] == 1) {
        search(x-1, y-1);
        ans += str1[y-1];
    }
    else if (mark[y][x] == 2)
        search(x, y-1);
    else 
        search(x-1, y);
}