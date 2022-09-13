#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> v1d;
typedef vector<v1d> v2d;

void output_LCS(v2d& dir, string& text1, int x, int y) {
    if(x == 0 || y == 0) return;

    if(dir[y][x] = 0) {
        cout << text1[y];
        output_LCS(dir, text1, x-1, y-1);
    }
    else if(dir[y][x] == 1) {
        output_LCS(dir, text1, x-1, y);
    }
    else {
        output_LCS(dir, text1, x, y-1);
    }
}


int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t--) {
        string text1, text2;
        cin >> text1 >> text2;
        int text1len = text1.length(), text2len = text2.length();
        v1d column(text2len+1, 0);
        v2d dp(text1len+1, column);
        v2d dir(text1len+1, column);//左上:0, 左:1, 上:2
        for(int i = 1; i <= text1len; i++) {
            for(int j = 1; j <= text2len; j++) {
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1]+1; 
                    dir[i][j]=0;
                }
                else {
                    if(dp[i-1][j] > dp[i][j-1]) {
                        dp[i][j] = dp[i-1][j];
                        dir[i][j] = 2;
                    }
                    else {
                        dp[i][j] = dp[i][j-1]; 
                        dir[i][j] = 1;
                    }
                }
            }
        }
        for(int i = 1; i <= text1len; i++) {//////
            for(int j = 1; j <= text2len; j++) {
                cout << dir[i][j] << " ";
            }
            cout << endl;
        }/////////////
        cout << "Case #" << t << ": " << dp[text1len][text2len] << endl;
        output_LCS(dir, text1, text2len, text1len);
    }
}

