#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        //nums.insert(nums.begin(), 0);
        vector<int> ans;
        deque<pair<int, int> > l, r; //first: idx
        for (int i = 0; i < k; i++) {
            if (!l.empty() && nums[i] > l.back().second) l.clear();
            l.push_back({i, nums[i]});
        }
        for (int i = k+1; i <= min(2*k, n-1); i++) {
            if (!r.empty() && nums[i] < r.back().second) r.clear();
            r.push_back({i, nums[i]});
        }
        for (int i = k; i < n - k; i++) {
            //cout << l.size() << " " << r.size() << "\n";
            while (!l.empty() && l.front().first < i - k) l.pop_front();
            while (!r.empty() && r.front().first <= i) r.pop_front();
            //cout << l.size() << " " << r.size() << "\n";
            if (l.size() == r.size() && r.size() == k) ans.push_back(i);

            if (!l.empty() && nums[i] > l.back().second) l.clear();
            l.push_back({i, nums[i]});
            if (i+k+1 < n && !r.empty() && nums[i+k+1] < r.back().second) r.clear();
            if (i+k+1 < n) r.push_back({i+k+1, nums[i+k+1]});
        }
        return ans;
    }
};