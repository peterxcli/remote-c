#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<int> row(obstacleGrid[0].size(), 0);
        vector<vector<int>> dp(obstacleGrid.size(), row);
        for(int i = 0; i < obstacleGrid[0].size(); i++) {
            if (obstacleGrid[0][i] == 0) dp[0][i] = 1; //邊界能到達的路徑數為1
            else break;//遇到障礙物之後的每格到達路徑數都設為0(已經dp陣列已經預設為0所以直接跳掉即可)
        }
        for(int i = 0; i < obstacleGrid.size(); i++) {
            if (obstacleGrid[i][0] == 0) dp[i][0] = 1;//邊界能到達的路徑數為1
            else break; //遇到障礙物之後的每格到達路徑數都設為0(已經dp陣列已經預設為0所以直接跳掉即可)
        }
        for (int i = 1; i < obstacleGrid.size(); i++) {
            for (int j = 1; j < obstacleGrid[0].size(); j++) {
                if (obstacleGrid[i][j] == 1) dp[i][j] = 0; //障礙物的到達路徑數設為0
                else dp[i][j] = dp[i-1][j] + dp[i][j-1]; // 到達路徑數為左邊那格及上面那格的到達路徑數相加(只能往下及右走)
            }
        }
        return dp.back().back(); // 回傳dp[m-1][n-1]
        // return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1]; //return答案 可改成這行
    }
};