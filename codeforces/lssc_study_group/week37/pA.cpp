#include <iostream>
#include <math.h>

using namespace std;

typedef unsigned long long ull;

int main() {
    ull k, n, w, price;
    cin >> k >> n >> w;
    price = k*(w*(w+1)/2);
    if(price > n) cout << price-n << endl;
    else cout << 0 << endl;
}