#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main() {
    int N, R;
    while (cin >> N >> R) {
        vector<bool> p(N+1, 0);
        int serial;
        for(int i = 0; i < R; i++) {
            cin >> serial;
            p[serial] = 1;
        }
        if (N == R) {cout << "*" << endl;continue;}
        for(int i = 1; i <= N; i++) {
            if(p[i] == 0) cout << i << " ";
        }
        cout << endl;
    }
}