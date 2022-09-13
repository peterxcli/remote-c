#include <bits/stdc++.h>

using namespace std;

struct Status {
    string sign;
    int64_t temp;
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int64_t n, a[200105], ans = 0;
        Status status;
        cin >> n;
        for(int i = 0 ; i < n; i++) 
            cin >> a[i];
        if (a[0] > 0) status.sign = "positive";
        else status.sign = "negative";
        status.temp = a[0];
        ans += a[0];
        for(int i = 1; i < n ; i++) {
            if(status.sign == "positive") {
                if(a[i] > 0) {
                    if(a[i] > status.temp) {
                        ans = ans-status.temp+a[i];
                        status.temp = a[i];
                    }
                }
                else {
                    status.sign = "negative";
                    status.temp = a[i];
                    ans += a[i];
                }
            }
            if(status.sign == "negative") {
                if(a[i] > 0) {
                    status.sign = "positive";
                    status.temp = a[i];
                    ans += a[i];
                }
                else {
                    if(a[i] > status.temp) {
                        ans = ans-status.temp+a[i];
                        status.temp = a[i];
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
