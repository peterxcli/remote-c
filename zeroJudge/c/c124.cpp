#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int L, R, C, ans, dist[35][35][35];
bool flag, is_used[35][35][35];
char castle[35][35][35];

struct point{
    int x, y, z;
};

void search();
bool is_valid(int x, int y, int z);

point start;


int main() {
    while(cin >> L >> R >> C && L != 0) {
        flag = false, ans = INT32_MAX;
        for(int i = 0; i < L; i++) {
            for(int j = 0; j < R; j++) {
                cin >> castle[i][j];
            }
        }
        search();
        if(flag)
            cout << "Escaped in " << ans << " minute(s)." << endl;
        else 
            cout << "Trapped!" << endl;
    }
}

void search() {
    memset(is_used, false, sizeof(is_used));
    for(int i = 0; i < L; i++) {
        for(int j = 0; j < R; j++) {
            for(int k = 0; k < C; k++) {
                if (castle[i][j][k] == 'S') {
                    start.x = k, start.y = j, start.z = i;
                    dist[i][j][k] = 0;
                    is_used[i][j][k] = true;
                }
            }
        }
    }
    queue<point> q;
    int dir[6][3] = {{0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};//x y z
    q.push(start);
    while(!q.empty()) {
        point root = q.front();
        q.pop();
        if(castle[root.z][root.y][root.x] == 'E') {
            flag = true;
            ans = dist[root.z][root.y][root.x];
            break;
        }
        for(int i = 0; i < 6; i++) {
            int new_x = root.x + dir[i][0], new_y = root.y + dir[i][1], new_z = root.z + dir[i][2];
            if(is_valid(new_x, new_y, new_z)) {
                dist[new_z][new_y][new_x] = dist[root.z][root.y][root.x]+1;
                is_used[new_z][new_y][new_x] = true;
                point next_root{new_x, new_y, new_z};
                q.push(next_root);
            }
        }
    }
}

bool is_valid(int x, int y, int z) {
    if(x >= 0 && y >= 0 && z >= 0 && x < C && y < R && z < L && castle[z][y][x] != '#' && is_used[z][y][x] == false)
        return true;
    else return false;
}