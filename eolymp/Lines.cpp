#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int n;
char grid[55][55];
int start_x = -1, start_y = -1, end_x = -1, end_y = -1;
bool flag = false, is_visited[55][55];
struct status {
    vector<pair<int, int> > pos;
};

vector<pair<int, int> > ans;

void search();
bool is_vaild(int x, int y);

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", grid[i]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] == 'X') {
                start_x = j, start_y = i;
            }
            else if(grid[i][j] == '@') {
                end_x = j, end_y = i;
            }
        }
    }
    search();
    if (flag) {
        printf("Y\n");
        for (int i = 0; i < ans.size(); i++) grid[ans[i].second][ans[i].first] = '+'; 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%c", grid[i][j]);
            }
            printf("\n");
        }
    }
    else printf("N\n");

}

bool is_vaild(int x, int y) {
    if (x >= n || y >= n || x < 0 || y < 0 || grid[y][x] == 'O' || is_visited[y][x] == true)
        return false;
    else 
        return true;
}

void search() {
    queue <status> q;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    status start;
    start.pos.push_back(make_pair(start_x, start_y));
    q.push(start);
    while (!q.empty()) {
        status cur = q.front();
        int cur_x = cur.pos.back().first, cur_y = cur.pos.back().second;
        if (cur_x == end_x && cur_y == end_y) {
            flag = true;
            ans = cur.pos;
            ans.pop_back();
        }
        q.pop();
        for(int i = 0; i < 4; i++) {
            if (is_vaild(cur_x + dir[i][0], cur_y + dir[i][1])) {
                status temp = cur;
                temp.pos.push_back(make_pair(cur_x + dir[i][0], cur_y + dir[i][1]));
                is_visited[cur_y + dir[i][1]][cur_x + dir[i][0]] = true;
                q.push(temp);
            }
        }
    }
}