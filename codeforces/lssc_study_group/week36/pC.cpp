#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <vector>

#define COUNT_MID 100000

typedef long long ll;

using namespace std;

ll len;
string arr;

int T, sum[100000], cnt[900090];

int main() {
    cin >> T;
    ll ans;
    while(T--) {
        memset(cnt, 0, sizeof(cnt)), ans=0, memset(sum, 0, sizeof(sum));
        cin >> len >> arr;
        sum[0] = arr[0]-'1';
        for(int i = 1; i < len; i++) {
            sum[i] += (sum[i-1]+arr[i]-'1');
        }
        cnt[COUNT_MID]++;
        for(int i = 0; i < len; i++) {
            ans += cnt[COUNT_MID+sum[i]];
            cnt[COUNT_MID+sum[i]]++;
        }
        cout << ans << endl;//01-1, 010
    }
}