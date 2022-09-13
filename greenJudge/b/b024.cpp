#include<iostream>
using namespace std;
int climb_stair(int N);
int main(){
    long long int step[100];
    int N; cin >> N;
    step[0] = 1; step[1] = 2;
    for(int i = 2; i < N; i++)
        step[i] = step[i - 1] + step[i - 2];
    cout << step[N - 1] << " " << step[step[N - 1] % N - 1];
}

int climb_stair(int N){
    return 0;
}