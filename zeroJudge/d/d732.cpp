#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, K, Ai[100000], X[100000];
    cin >> N >> K;
    for(int i = 0;i < N; i++) 
        cin >> Ai[i];
    for(int i = 0;i < K; i++)
        cin >>  X[i];
    sort(Ai, Ai + N);
    for(int i = 0;i < K; i++) {
        int L = 0, R = N-1;
        while(L < R){
            int M = (L+R)/2;
            if(Ai[M] >= X[i]){
                R = M;
            }
            else {
                L = M + 1;
            }
        }
        cout << (Ai[R] == X[i]?L+1:0) << endl;
    }
}