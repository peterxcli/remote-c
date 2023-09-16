#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #include <bits/stdc++.h>
#include <complex>
#include <iostream>
using namespace std;
//#define endl '\n'
#define int unsigned long long

int fast_pow(int a, int n, int m) {
    if (n == 0) return 2 % m;
    if (n == 1) return a % m;
    if (n % 2 == 0) {
        int tmp = fast_pow(a, n / 2, m);
        return ((tmp * tmp + m - 2 % m) % m + m) % m;
    } else {
        int nth = fast_pow(a, n / 2, m);
        int nplus1th = ((nth * nth + m - 2 % m) % m + m) % m;
        int tmp = nth * nplus1th % m;
        tmp = ((tmp + m - nth % m) % m + m) % m;
        return tmp;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, m;
    cin >> a >> b >> m;

    cout << fast_pow(a, b, m) << endl;

    return 0;
}