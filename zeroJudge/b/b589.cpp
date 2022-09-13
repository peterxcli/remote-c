#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

#define DP true

int n, P[50];

int dfs(int cur, int Magnification);
int dp_f();

int main() {
    while (true) {
        cin >> n;
        if(n != 0) {
            for(int i = 0; i < n; i++)
                cin >> P[i];
            cout << (DP?dp_f():max(dfs(0, 1), dfs(0, 2))) << endl;
            
        }
        else {
            return 0;
        }
    }
}

int dfs(int cur, int Magnification) {
    if(Magnification == 2) {
        if(cur == n){
            return 0;
        }
        else{
            return dfs(cur + 1, 0) + P[cur]*2;
        }
    }
    else if(Magnification == 1) {
        if(cur == n){
            return 0;
        }
        else{
            return max(dfs(cur + 1, 1) + P[cur], dfs(cur + 1, 2) + P[cur]);
        }
    }
    else {
        if(cur == n){
            return 0;
        }
        else{
            return max(dfs(cur + 1, 1), dfs(cur + 1, 2));
        }
    }
}

int dp_f() {
        int dp[50] = {0};
        for(int i=0;i<n;i++)
        {
            dp[i+1] = max(dp[i+1],dp[i]+P[i]);
            dp[i+2] = max(dp[i+2],dp[i]+2*P[i]);
        }
        return max(dp[n],dp[n+1]);
}