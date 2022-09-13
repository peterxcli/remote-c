//link:https://zerojudge.tw/ShowProblem?problemid=d799
#include <bits/stdc++.h>

using namespace std;

vector<int> segment_tree, a;

void build(int L, int R, int node) {
    if (L == R) {
        segment_tree[node] = a[L];
        return;
    }
    int M = (L+R)/2;
    build(L, M, 2*node+1);
    build(M+1, R, 2*node+2);
    segment_tree[node] = segment_tree[2*node+1] + segment_tree[2*node+2];
}

void update(int u, int L, int R, int v, int node) {
    if (L == R) { 
        segment_tree[node] = v;
        return;
    }
    int M = (L+R)/2;
    if (u <= M) update(u, L, M, v, 2*node+1);
    else update(u, M+1, R, v, 2*node+2);
    segment_tree[node] = segment_tree[2*node+1]+segment_tree[2*node+2];
}

int query(int qL, int qR, int L, int R, int node) {
    if (L >= qL && qR >= R) return segment_tree[node];
    int M = (L+R)/2;
    int ret = 0;
    if (qL <= M) ret += query(qL, qR, L, M, 2*node+1);
    if (qR > M) ret += query(qL, qR, M+1, R, 2*node+2);
    return ret;
}

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int N;
    cin >> N;
    a.resize(N), segment_tree.resize(4*N+5), b.resize(4*N+5);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    build(0, N-1, 0);
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int v, x, y, k;
        cin >> v;
        if (v == 1) {
            cin >> x >> y >> k;
            update(x-1, y-1, 0, N-1, k, 0);
        }
        else { 
            cin >> x >> y;
            cout << query(x-1, y-1, 0, N-1, 0) << "\n";
        }
    }
}