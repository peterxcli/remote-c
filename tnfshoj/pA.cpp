#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    ll ans = 0;
    scanf("%lld", &N);

    for(int i = 0; i < N; i++) {
        ll tmp;
        scanf("%lld", &tmp);
        ans += tmp;
    }

    scanf("%lld", &M);

    for(int i = 0; i < M; i++) {
        ll l, r, w;
        scanf("%lld %lld %lld", &l, &r, &w);
        ans += ((r-l+1) * w);
        printf("%lld\n", ans);
    }
}