#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> shape;  //First:X, Second:Y 
typedef vector<shape> Doll;

shape readDoll();
int LIS(Doll &);
bool cmp(shape , shape);

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        Doll list;
        while(N--) list.push_back(readDoll());
        sort(list.begin(), list.end(), cmp);
        cout << LIS(list) << endl;
    }
}

bool cmp(shape a, shape b) {
    if(a.first == b.first) return a.second > b.second;
    else return (a.first < b.first);
}

int LIS(Doll &dolls) {
        sort(dolls.begin(), dolls.end(),cmp);
        vector<int> dp2;
        dp2.push_back(dolls[0].second);
        for(int i = 0;i < dolls.size();i++){
            if(dolls[i].second > dp2.back()) dp2.push_back(dolls[i].second);
            else *lower_bound(dp2.begin(), dp2.end(), dolls[i].second) = dolls[i].second;
        }
        return dp2.size();
    }

shape readDoll() {
    shape doll;
    cin >> doll.first >> doll.second; 
    return doll;
}