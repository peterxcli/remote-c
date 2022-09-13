#include <iostream>

using namespace std;

int row, column, ans = 0, max = 0;

char map[25][25];

bool is_used[25][25] = {false};

int is_valid(int x, int y);
void search(int x, int y);

int main() {
    while(cin >> row >> column){
        ans=0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                cin >> map[i][j];
            }
        }
        int x, y;
        cin >> x >> y;
        if(is_valid(x, y))
            search(x, y);
        cout << ans << endl;
    }
}

int is_valid(int x, int y) {
    if(map[y][x] == 'l' && y < row && y >= 0 &&is_used[y][x] == false)
        return true;
    else
        return false;
}

void search(int x, int y) {
    is_used[y][x] = true;
    ans++;
    int dir[4][2] = {{0,-1},{1,0},{0,1},{-1,0}};
	for(int i = 0; i < 4; i++){
        int _X = x + dir[i][0], _Y = y + dir[i][1];
		if(_X < 0) {_X = column-1;} else if(_X > column-1) {_X = 0;}
        if(is_valid(_X, _Y))
            search(_X, _Y);
    }
    is_used[y][x] = false;
}