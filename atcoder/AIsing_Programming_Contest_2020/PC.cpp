#include <iostream>

using namespace std;

int dp(int x, int y, int z, int n);

int N, storge[10000], ans, var; ;

int main() {
    
    cin >> N;
 
    for(int i = 0; i < N; i++){
        cin >> var;
        ans = 0;
        dp();
        cout << ans << endl;
    }
    return 0;
}

int dp(int x, int y, int z, int n) {
    
}