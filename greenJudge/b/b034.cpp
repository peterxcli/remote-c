#include <iostream>

using namespace std;
int main() {
    int coin[] = {1, 5, 10, 50, 100, 500, 1000, 5000, 10000}, price, Q = 0;
    cin >> price;
    for(int i = 8; i >= 0; i--) {
        if(price >= coin[i]) {
            Q += price / coin[i];
            price %= coin[i]; 
        }
    }
    cout << Q << endl;
}