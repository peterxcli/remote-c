#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    if(N % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    cout << (int)pow(2, N/2) << endl;
}
