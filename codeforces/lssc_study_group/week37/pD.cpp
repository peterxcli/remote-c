#include <iostream>
#include <string>
#include <queue>

using namespace std;


struct state {
    //0:left, 1:right
    bool wall;
    uint64_t height;
    uint64_t Water_surface_height;
}Vasya;

//[0]:left, [1]:right
bool flag = false, is_visted[2][100005]={0};
uint64_t n, k;
string Wall[2];

void game_start();

int main() {
    cin >> n >> k;
    Vasya.height = 1, Vasya.wall = 0, Vasya.Water_surface_height = 0;
    cin >> Wall[0] >> Wall[1];
    game_start();
    cout << (flag?"YES":"NO");
}

void game_start() {
    char dir[3] = {'u', 'd', 'j'};
    queue<state> q;
    q.push(Vasya);
    while(!q.empty()) {
        Vasya = q.front();
        if (flag) break;
        q.pop();
        for(int i = 0; i < 3; i++) {
            state temp = Vasya;
            if(dir[i] == 'u'){
                temp.height++;
                temp.Water_surface_height++;
                if(temp.height > n) {flag = true; break;}
                if(!is_visted[temp.wall][temp.height-1] && temp.height > temp.Water_surface_height && Wall[temp.wall][temp.height-1] == '-') {
                    is_visted[temp.wall][temp.height-1] = true;
                    q.push(temp);
                }
            }
            else if(dir[i] == 'd'){
                if (temp.height == 1) continue;
                temp.height--;
                temp.Water_surface_height++;
                if(!is_visted[temp.wall][temp.height-1] && temp.height > temp.Water_surface_height && Wall[temp.wall][temp.height-1] == '-') {
                    is_visted[temp.wall][temp.height-1] = true;
                    q.push(temp);
                }
            }
            else {
                temp.wall = !temp.wall;
                temp.height += k;
                temp.Water_surface_height++;
                if(temp.height > n) {flag = true; break;}
                if(!is_visted[temp.wall][temp.height-1] && temp.height > temp.Water_surface_height && Wall[temp.wall][temp.height-1] == '-') {
                    is_visted[temp.wall][temp.height-1] = true;
                    q.push(temp);
                }
            }
        }
    }
}