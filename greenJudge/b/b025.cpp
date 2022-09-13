#include<iostream>
using namespace std;
void stair_walk(int &X, int &Y);
int main(){
    int X, Y;
    // stair[1][2] = -1;
    cin >> X >> Y;
    stair_walk(X, Y);
}

void stair_walk(int &X, int &Y){
    long long int stair[35][35];
    for(int i = 0; i <= X; i++){
        stair[0][i] = 1;
    }
    for(int i = 0; i <= Y; i++){
        stair[i][0] = 1;
    }
    for(int i = 1; i <= X; i++){
        for(int j = 1; j <= Y; j++){
            stair[j][i] = stair[j][i - 1] + stair[j - 1][i];
        }
    }
    cout << stair[Y][X];
}

void stair_walk_dp(int &X, int &Y){
    long long int stair[2][35] = {0};
    // for(int i = 0; i <= X; i++){
    //     stair[0][i] = 1;
    // }
    // for(int i = 0; i <= Y; i++){
    //     stair[i][0] = 1;
    // }
    for(int i = 1; i <= X; i++){
        for(int j = 1; j <= Y; j++){
            
        }
    }
    cout << stair[Y][X];
}