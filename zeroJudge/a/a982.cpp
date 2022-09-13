#include <iostream>

using namespace std;

int N, Minimum = INT32_MAX;

char map[100][100];

bool is_used[100][100] = {false};
int rec[100][100] = {0};

int is_valid(int x, int y);
void solve(int x, int y, int Step);

int main() {
        cin >> N;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> map[i][j];
            }
        }
        if(is_valid(1, 1))
            solve(1, 1, 0);
        if(Minimum != INT32_MAX)
            cout << Minimum << endl;
        else 
            cout << "No solution!" << endl;
}

int is_valid(int x, int y) {
    // if(map[y][x] == '.' && y < N && y >= 0 && x < N && x >= 0 && is_used[y][x] == false)
    //     return true;
    // else
    //     return false;
    if(y < N && y >= 0 && x < N && x >= 0 && is_used[y][x] == false && map[y][x] == '.')
        return true;
    else
        return false;
}

void solve(int x, int y, int Step) {
    Step++;
    if(x == N-2 && y == N-2) {
        Minimum = min(Minimum, Step);
        return;
    }
    is_used[y][x] = true;
    int dir[4][2] = {{0,-1},{1,0},{0,1},{-1,0}};
	for(int i = 0; i < 4; i++){
        int _X = x + dir[i][0], _Y = y + dir[i][1];
        if(is_valid(_X, _Y))
            solve(_X, _Y, Step);
    }
    is_used[y][x] = false;
}