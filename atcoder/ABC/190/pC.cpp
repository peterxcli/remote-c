#include <bits/stdc++.h>

using namespace std;

struct condi{
    int A, B;
}conditions[105];

struct person{
    int C, D;
}people[20];

int N, M, K;

vector<vector<int> > S;

void build(int cur, int pos, vector<int> tmp) {
    if (cur > 0) tmp[pos] += 1;
    if (cur == K) {
        S.push_back(tmp);
        return;
    }
    build(cur+1, people[cur+1].C, tmp);
    build(cur+1, people[cur+1].D, tmp);
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
        cin >> conditions[i].A >> conditions[i].B;
    cin >> K;
    for (int i = 1; i <= K; i++) {
        cin >> people[i].C >> people[i].D;
    }
    vector<int> tmp;
    tmp.resize(N+1);
    build(0, 0, tmp);
    int ans = 0;
    for (int i = 0; i < S.size(); i++) {
        int tmp = 0;
        for (int j = 1; j <= M; j++) {
            if (S[i][conditions[j].A] && S[i][conditions[j].B]) tmp++;
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}