#include<iostream>

using namespace std;

int main() {
    int H, W, grid[105][105], dp[105][105];
    cin >> H >> W;

    for(int i = 0; i <= H; i++) dp[i][0] = 0;
    for(int i = 0; i <= W; i++) dp[0][i] = 0;

    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            if(grid[i][j] == 0){
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    int maxSquare = 0;
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            maxSquare = max(maxSquare, dp[i][j]);
        }
    }
    cout << maxSquare*maxSquare << endl;
}
