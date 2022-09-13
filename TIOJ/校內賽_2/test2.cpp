#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool flag = false;
int ans = 0;
int n, k;
string ori, target;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        char temp;
        cin >> temp;
        ori += temp;
    } 
        
    for (int i = 0; i < n; i++){
        char temp;
        cin >> temp;
        target += temp;
    } 
    // if (ori[0] - target[0] == ori[1] - target[1]) {
    //     ans = min(ori[0] - target[0], )
    // }
    // else {
    //     cout << "0\n";
    // }
    
    for (int i = 1; i <= 10; i++) {

        if (ori[0] + 1 > '9') 
            ori[0] = '1';
        else ori[0] ++;

        if (ori[1] + 1 > '9') 
            ori[1] = '1';
        else ori[1]++;

        if (ori == target) {
            ans = i;
            break;
        }
    }
    printf("%d\n", ans);
    
}

