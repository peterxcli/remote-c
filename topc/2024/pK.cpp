#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int> > adj(n + 1);
    vector<int> in_degree(n + 1, 0);
    priority_queue<int, vector<int>, greater<int> > pq;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        in_degree[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> result;
    while (!pq.empty()) {
        int curr = pq.top();
        pq.pop();
        result.push_back(curr);

        for (int neighbor : adj[curr]) {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) {
                pq.push(neighbor);
            }
        }
    }

    if (result.size() == n) {
        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
    } else {
        cout << "IMPOSSIBLE" << "\n";
    }

    return 0;
}
