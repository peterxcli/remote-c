#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if (C == 0) {
        if (A > B) cout << "Takahashi" << endl;
        else cout << "Aoki" << endl;
    }
    else if (C == 1){
        if (A < B) cout << "Aoki" << endl;
        else cout << "Takahashi" << endl;
    }
}