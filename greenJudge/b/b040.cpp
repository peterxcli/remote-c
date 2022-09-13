#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> v1d;
typedef vector<v1d> v2d;

int N, M;
bool is_used[25] = {false}, flag = false;
v1d itemPrice(25, 0);

void print(int cur, v1d rec, int sum);
void fcout (v1d &arr);

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) 
        cin >> itemPrice[i];
    v1d start;
    print(0, start, 0);
    if(!flag) cout << "NO" << endl;
}

void print(int cur, v1d rec, int sum) {
    
    if(sum == M) {
        fcout(rec);
        flag = true;
        return;
    }
    if(cur >= N || sum > M) return;

    rec.push_back(itemPrice[cur]);
    print(cur+1, rec, sum+itemPrice[cur]);
    rec.pop_back();
    print(cur+1, rec, sum);
}

void fcout (v1d &arr) {
    for(int i = 0; i < arr.size(); i++) cout << arr.at(i) << (i!=arr.size()-1?" ":"\n");
}