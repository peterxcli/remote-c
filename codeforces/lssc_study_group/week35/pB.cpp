#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

double hot, cold, target;
int serach();

int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> hot >> cold >> target;
        cout << serach() << endl;
    }
}

int serach() {
    int l = 0, r = 1000000;
    while (l < r){
        int mid = (l + r) / 2;
        if ((hot * (mid + 1) + cold * mid) / (2.0 * mid + 1) > target)
            l = mid + 1;
        else
            r = mid;
    }
    double diff = abs((hot+cold)/2-target), ans = 2;
    for(int i = max(0, l - 10); i <= l + 10; i++) {
        double temp = (hot * (i + 1) + cold * i) / (2.0 * i + 1);
        if (abs(temp - target) < diff) {
            ans = 2 * i + 1;
            diff  = abs(temp - target);
        }
    }
    return ans;
}