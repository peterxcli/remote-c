#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string> > p(n);
        for (int i = 0; i < n; i++) {
            p[i] = make_pair(heights[i], names[i]);
        }
        sort(p.begin(), p.end());
        reverse(p.begin(), p.end());
        vector<string> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = p[i].second;
        }
        return ans;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}