#include <iostream>
#define N 1000
int prince[1001], bag[5]={2, 5, 10, 20, 25};

int main(){
    int n;
    std::cin >> n;
    prince[0] =  1;
    for (int i = 1; i <= N; i++)
        prince[i]=0;
    for (int i = 0; i < 5; i++)
        for (int j = bag[i]; j <= N; j++)
            prince[j] += prince[j - bag[i]];

    std::cout << prince[n];
}
