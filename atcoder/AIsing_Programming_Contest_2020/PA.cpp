#include <iostream>

using namespace std;

int main() {
    int L, R, d;
    cin >> L >> R >> d;
    int ans = 0;
    for(int i = 0; ; i++) {
        if(d*i >= L && d*i <= R) {
            ans++;
        }
        else if(d*i > R)
            break;
    }
    
    cout << ans << endl;
}