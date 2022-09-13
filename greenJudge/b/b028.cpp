#include<iostream>
#include<algorithm>
//using namespace std;

int way(int price);

int coin[] = {1, 5, 10, 12, 16, 20};
int dp[100] = {0};
int main(){
    int price;
    std::cin >> price;
    std::cout << way(price);
}

int way(int price){
    if(dp[price]){
      return dp[price];
    }
    if(price == 0){
        return dp[price] = 0;
    }
    else{
        int min = 200000000, min_i = 0;

        for(int i = 5; i >= 0; i--){
            if(price >= coin[i] ){
                if(min > way(price - coin[i])){
                    min = way(price - coin[i]);
                    min_i = i;
                }
            }
        }
        return dp[price] = min + 1;
    }
}