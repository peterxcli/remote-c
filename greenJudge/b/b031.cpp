#include <iostream>

using namespace std;

int knapsack(int , int);

int L[105], S[105];
int table[105][1005] = {0};

int main() {
    int N, M;
    cin >> N >> M;
    for(int i = 1 ; i <= N; i++)
        cin >> L[i] >> S[i];

    cout << knapsack(N, M) << endl;
}

int knapsack(int n, int w) {
    if(w < 0) return -100000000;
    if(n == 0) return 0;
    
    if(table[n][w]) return table[n][w];

    return table[n][w] = max(
        knapsack(n-1, w), 
        knapsack(n, w-L[n]) + S[n]
    );

}
