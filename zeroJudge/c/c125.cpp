#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define MAX_NODE 205
using namespace std;

vector<int> edge[MAX_NODE];
vector<int> weight[MAX_NODE];

struct NODE{
    int x, y;
}rock[MAX_NODE];

int N, t = 0;

int main() {
    while (cin >> N && N != 0) {

        vector<int> node[MAX_NODE];
        vector<int> weight[MAX_NODE];
        int visted[MAX_NODE] = {0};

        for(int i = 1; i <= N; i++)
            cin >> rock[i].x >> rock[i].y;
        
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(i != j) {
                    node[i].push_back(j);
                    weight[i].push_back((rock[j].x-rock[i].x)*(rock[j].x-rock[i].x) + (rock[j].y-rock[i].y)*(rock[j].y-rock[i].y));
                }
            }
        }

        priority_queue<
            pair <int,int>,
            vector <pair <int,int> >,
            greater <pair <int,int> >
        > pq;//first:weight, second:num

        pq.push(make_pair(1, 0));

        int shortest = INT32_MAX;

        while(!pq.empty()) {
            pair<int, int> cur = pq.top();
            pq.pop();

            if(visted[])
        }
    }
}

void search() {
    
}
