#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> v1d;
typedef vector<v1d> v2d;
int highestTower(v2d& blocks);

void addBlock(v2d& blocks);
bool cmp(v1d a, v1d b);

int main() {
    int N, T = 0;
    while (cin >> N && N != 0) {
        v2d blocks;
        for(int i = 0; i < N; i++) 
            addBlock(blocks); 
        cout << "Case " << ++T << ": maximum height = " << highestTower(blocks) << endl;   
    }
}

int highestTower(v2d& blocks) {
    sort(blocks.begin(), blocks.end(), cmp);
    v1d dp(blocks.size(), 0);
    for(int i = 0; i < blocks.size(); i++) dp[i] = blocks.at(i).at(2);
    for(int i = 0; i < blocks.size(); i++) {
        for(int j = i+1; j < blocks.size(); j++) {
            if(blocks[i][0] < blocks[j][0] && blocks[i][1] < blocks[j][1]) {
                dp[j] = max(dp[j], dp[i] + blocks[j][2]);
            }
        }
    }
    int maxheight = 0;
    for(int i = 0; i < dp.size(); i++)
        maxheight = max(maxheight, dp.at(i));
    return maxheight;
}

void addBlock(v2d& blocks) {
    v1d oneBlock;
    int temp;
    for(int i = 0; i < 3; i++) {cin >> temp; oneBlock.push_back(temp);}
    sort(oneBlock.begin(), oneBlock.end());
    do{
        blocks.push_back(oneBlock);
        // for (int i = 0; i < oneBlock.size(); i++) cout << oneBlock[i] << (i!=2?" ":"\n");////////////////
    }
    while(next_permutation(oneBlock.begin(), oneBlock.end()));
    // cout << endl;//////////////////////
}

bool cmp(v1d a, v1d b) {
    if(a[0] == b[0]) return a[1] < a[1];
    else return a[0] < b[0];
}