#include "../testlib/testlib.h"
#include <bits/stdc++.h>

using namespace std;

int a[1000005], diff[1000005], res[1000005];

void solveTest(int test) {
    string inputFile = "testcase/" + to_string(test) + ".in";
    string outputFile = "testcase/" + to_string(test) + ".out";
    freopen(inputFile.c_str(), "r", stdin);
    freopen(outputFile.c_str(), "w", stdout);
    int n;
    cin >> n;
    priority_queue<int, vector<int>>
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

    }
    for (int i = 2; i <= n; i++) diff[i] = a[i] - a[i-1];
}

int main(int argc, char *argv[]) {
    //cin.tie(0), ios_base::sync_with_stdio(0);
    registerGen(argc, argv, 1);

    for (int i = 1; i <= 10; i++)
        solveTest(i);
}