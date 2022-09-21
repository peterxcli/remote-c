#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int n, x[N], y[N], a[N], l;
int dis(int i,int j){return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);}
signed main() {
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin >> x[i] >> y[i];
	l = 1, a[1] = 1;
	cout << 1 << ' ';
	for(int i = 2; i <= n; i++) {
		int x = -1;
		for(int j = 1; j <= n; j++)
			if(!a[j] && (x == -1|| dis(l,j)>dis(l,x)))
				x = j;
		a[x] = 1;
		l = x;
		cout << x << ' ';
	}
	return 0;
}