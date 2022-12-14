// We can calculate the number of inversions in the original array in a number of ways, such as with a Fenwick tree or with merge sort.
// Now, notice that each of the resulting sequences essentially remove the first element of the previous sequence and insert it at the end of it. 
// This changes the number of inversions in the new sequence by nā1ā2a(i) for each i from 0 to Nā2.

// Time complexity: O(NlogN) for calculating inversions

#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int maxn = (int)3e5+5;
int n, a[maxn], b[maxn], c[maxn];
 
ll find_inversions(int l, int r) {
    if (l == r)
        return 0;
    int m = (l+r)>>1, x = l, y = m+1;
    ll ans = find_inversions(l, m) + find_inversions(m+1, r);
    for (int i = l; i <= r; i++) {
        if (x > m)
            c[i] = b[y++];
        else if (y>r)
            c[i] = b[x++];
        else if (b[x]>b[y]) {
            c[i] = b[y++];
            ans += m-x+1;
        }
        else
            c[i] = b[x++];
    }
    for (int i = l; i <= r; i++)
        b[i] = c[i];
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    ll cur = find_inversions(0,n-1);
    cout << cur << "\n";
    for (int i = 0; i+1 < n; i++) {
        cur += n-1 - 2*a[i];
        cout << cur << "\n";
    }
    return 0;
}