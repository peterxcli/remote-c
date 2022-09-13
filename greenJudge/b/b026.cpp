#include<iostream>

int min(int a, int b, int c);

int main(){
    long long int input, N;
    int sum = 0, max = 0;
    std::cin >> N;
    for(int i = 0; i < N; i++){
        std::cin >> input;
        sum += input;
        if(sum > max) {
            max = sum;
        }
        if(sum < 0){
            sum = 0;
        }
    }
    std::cout << max;
    return 0;
}


