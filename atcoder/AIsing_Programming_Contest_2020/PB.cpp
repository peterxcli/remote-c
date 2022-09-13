#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int ans = 0, var;
    for(int i = 0; i < N; i++){
        cin >> var;
        if(i % 2 == 0 && var % 2 == 1) {
            ans ++;
        }
    }

    cout << ans << endl;
}