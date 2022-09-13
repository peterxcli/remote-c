#include <bits/stdc++.h>
#define inf (int)1e18
// #define inf (int)1e9
// #define int long long
#define N 1010
using namespace std;
typedef long long ll;
string grid[N];
int to[N][2];
int n, m;
void slove() {
    cin >> n >> m;
    for (int i = 0; i <= n; i++) to[i][0] = to[i][1] = -1;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            to[i][grid[i][j] - 'a'] = j;
        }
    }
    if (m & 1) {
        cout << "yes\n";
        for (int i = 0; i < m+1; i++) {
            if (i) cout << " ";
            cout << (i&1)+1;
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (grid[i][j] == grid[j][i]) {
                cout << "yes\n";
                for (int k = 0; k < m+1; k++) {
                    if (k) cout << " ";
                    cout << ((k&1)?i+1:j+1);
                }
                cout << "\n";
                return;
            }
        }
    }
    for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
		    if(i == j) continue;
                if(to[j][grid[i][j] - 'a'] == -1) continue;
                cout << "yes\n";
                int cur = to[j][grid[i][j] - 'a'];
                if((m / 2) % 2 == 1){
                    for(int k = 0 ; k < m+1; k++){
                        if(k) cout << " ";
                        if(k % 4 == 0)
                            cout << i+1;
                        else if(k % 4 == 2)
                            cout << cur+1;
                        else
                            cout << j+1;
                    }
                    cout << "\n";
                    return;
                }
                cout << j + 1;
                for(int k = 0 ;k < m / 2; k++){
                    cout << " " << ((k&1)?j+1:cur+1);
                }
                for(int k = 0 ;k < m / 2; k++){
                    cout << " " << ((k&1)?(j+1):(i+1));
                }
                cout << "\n";
                return;
        }
    }
    cout << "no\n";
    return;
}

int32_t main() {
    cin.tie(0), ios_base::sync_with_stdio(0);   
    int t;
    cin >> t;
    while(t--) {
        slove();
    }
}