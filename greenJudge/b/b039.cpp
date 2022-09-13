#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef vector<int> v1d;

bool col_used[100] = {false};
bool left_diag_used[100] = {false};
bool right_diag_used[100] = {false};

int N;

void print(v1d arr) {
    for(int i = 0; i < arr.size(); i++) cout << arr.at(i) << (i!=arr.size()-1?" ":"\n");
}

void search(int cur, int row, v1d rec) {

    if(cur == N) {
        print(rec);
        return;
    }
    for(int i = 0; i < N; i++) {
        if(!(col_used[i] || left_diag_used[i+row] || right_diag_used[N+i-row])) {
            col_used[i] = true;
            left_diag_used[i+row] = true;
            right_diag_used[N+i-row] = true;

            rec.push_back(i+1);
            search(cur+1, row+1, rec);
            rec.pop_back();

            col_used[i] = false;
            left_diag_used[i+row] = false;
            right_diag_used[N+i-row] = false;
        }
    }
}

int main() {
    cin >> N;
    v1d start;
    search(0, 0, start);
}