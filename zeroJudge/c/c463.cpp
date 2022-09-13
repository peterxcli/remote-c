#include <iostream>
#include <vector>

#define MAX_NODE 100000

using namespace std;

int main() {
    vector<int> node[MAX_NODE];
    int n, root;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++) {
            int new_node;
            cin >> new_node;
            node[i].push_back(new_node);
        }

    }
}

long long search() {
    
}

int search_root () {
    for (int )
}