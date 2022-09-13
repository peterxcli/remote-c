#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> v1d;
typedef vector<v1d> v2d;

void listAllPair(v2d& pairs, v1d& path1, v1d& path2);
int pairsLIS(v2d& pairs);
bool cmp(v1d a, v1d b);

int n, p, q;

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> n >> p >> q;
        v1d path1(p+1, 0), path2(q+1, 0);
        for(int i = 0; i <= p; i++) cin >> path1[i];
        for(int i = 0; i <= q; i++) cin >> path2[i];
        v2d pairs;
        listAllPair(pairs, path1, path2);
        // for(int i = 0; i < pairs.size(); i++) cout << pairs[i][0] << " " << pairs[i][1] << endl;
        cout << "Case " << t << ": " << pairsLIS(pairs) << endl;
    }
}

void listAllPair(v2d& pairs, v1d& path1, v1d& path2) {
    int N = n*n;
    v1d Pos1[N], Pos2[N];
    for(int i = 0; i < path1.size(); i++) {
        Pos1[path1[i]-1].push_back(i);
    }
    for(int i = 0; i < path2.size(); i++) {
        Pos2[path2[i]-1].push_back(i);
    }
    v1d Pair(2, 0);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < Pos1[i].size(); j++) {
            for(int k = 0; k < Pos2[i].size(); k++) {
                Pair[0] = Pos1[i][j], Pair[1] = Pos2[i][k];
                pairs.push_back(Pair);
            }
        }
    }
}

int pairsLIS(v2d& pairs) {
    sort(pairs.begin(), pairs.end(), cmp);
    v1d dp2(1, pairs[0][1]);
    for(int i = 0; i < pairs.size(); i++) {
        if (pairs[i][1] > dp2.back()) dp2.push_back(pairs[i][1]);
        else *lower_bound(dp2.begin(), dp2.end(), pairs[i][1]) = pairs[i][1];
    }
    return dp2.size();
}

bool cmp(v1d a, v1d b) {
    if(a[0] == b[0]) return a[1] > b[1];
    else return a[0] < b[0];
}