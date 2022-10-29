#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];
        int cur = nums[0];
        int len = 1;
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > mx) ans = 1, mx = nums[i];
            if (cur & nums[i] < cur) {
                cur = nums[i];
                len = 1;
            }
            else {
                cur &= nums[i];
                len++;
                if (cur >= mx) ans = len, mx = cur;
            }
        }
        return ans;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}