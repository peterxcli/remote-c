#include "../testlib/testlib.h"
#include <bits/stdc++.h>

using namespace std;
#define int long long

int a[1000005], diff[1000005], res[1000005];

void solveTest(int test) {
    string inputFile = "testcase/" + to_string(test) + ".in";
    string outputFile = "testcase/" + to_string(test) + ".out";
    freopen(inputFile.c_str(), "r", stdin);
    freopen(outputFile.c_str(), "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    diff[1] = a[1];
    for (int i = 2; i <= n; i++) diff[i] = a[i] - a[i-1];
    for (int i = 0; i < q; i++) {
        int l, r, v;
        cin >> l >> r >> v;
        diff[l] += v, diff[r+1] -= v;
    }
    for (int i = 1; i <= n; i++) res[i] = res[i-1] + diff[i];
    for (int i = 1; i <= n; i++) cout << res[i] << (i == n ? "\n" : " ");
}

int32_t main(int32_t argc, char *argv[]) {
    //cin.tie(0), ios_base::sync_with_stdio(0);
    registerGen(argc, argv, 1);

    for (int i = 1; i <= 10; i++)
        solveTest(i);
}