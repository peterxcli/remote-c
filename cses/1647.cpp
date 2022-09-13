//link:https://zerojudge.tw/ShowProblem?problemid=d539
#include <bits/stdc++.h>

using namespace std;

vector<int> segment_tree, T;

void build(int L, int R, int node) {
    if (L == R) {
        segment_tree[node] = T[L];
        return;
    }
    int M = (L+R)/2;
    build(L, M, 2*node+1);
    build(M+1, R, 2*node+2);
    segment_tree[node] =  min(segment_tree[2*node+1], segment_tree[2*node+2]);
}

int queryMax(int qL, int qR, int L, int R, int node) {
    if (L >= qL && qR >= R) return segment_tree[node];
    int M = (L+R)/2, ret = INT32_MAX;
    if (qL <= M) ret = min(ret, queryMax(qL, qR, L, M, 2*node+1));
    if (qR > M) ret = min(ret, queryMax(qL, qR, M+1, R, 2*node+2));
    return ret;
}

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int N, M;
    cin >> N >> M; 
    T.resize(N), segment_tree.resize(4*N+5);
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }
    build(0, N-1, 0);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        cout << queryMax(a-1, b-1, 0, N-1, 0) << "\n";
    }
}