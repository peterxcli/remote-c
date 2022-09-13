#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K, a[550]={0}, ans=0;
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for(int i = 1; i < N; i++) {
        if (a[i] + a[i-1] < K) {
            ans += K-(a[i]+a[i-1]);
            a[i] = K-a[i-1];
        } 
    }
    cout << ans << endl;
    for(int i = 0; i < N; i++) {
        cout << a[i] << (i!=N-1?" ":"\n");
    }
}
