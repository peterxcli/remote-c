#include <bits/stdc++.h>
using namespace std;
 
bool lucky(int x, int d) {
	while (x) {
		if ((x % 10) == d) return true;
		x /= 10;
	}
	return false;
}
 
int pos(int x, int d) {
	if (x == 0) return true;
	if (x < 0) return false;
	int m = 0;
	for (int i = d; i <= x; i++) {
		if (lucky(i, d)) m = max(m, pos(x - i, d));
	}
	return m;
}
 
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	int t;
	cin >> t;
	while (t--) {	
		int n, d;
		cin >> n >> d;
		vector<int> a(n);
 
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] >= d * 10 + 9 || pos(a[i], d)) {
				cout << "Yes\n";
			}
			else {
				cout << "No\n";
			}
		}
	}
}