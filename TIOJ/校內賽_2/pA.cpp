#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, a[1000000] = {0}, d[1000000] = {0}, ans = 0;

vector<int> 

bool visited[1000000] = {0};

bool lose(int i, int cur);

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n ; i++) 
        scanf("%d %d", &a[i], &d[i]);
    for (int i = 0; i < n; i++) {
        int counter = 0, cur = i;
        memset(visited, false, sizeof(visited));

        while (!lose(i, cur)) {
            if 
            if(cur == 0) {
                cur++;
            }
            else if (cur == n-1) {
                cur--;
            }
            else {
                if ((a[i] > a[cur-1] && d[i] >= d[cur-1]) || (a[i] >= a[cur-1] && d[i] > d[cur-1])) cur--;
                else cur++;
            }
            counter++;
        }
        cout << "hi\n";
        ans = max(ans, counter);
    }
    printf("%d\n", ans);
}

bool lose(int i, int cur) {
    if(cur == 0) {
        if ((a[i] > a[cur+1] && d[i] >= d[cur+1]) || (a[i] >= a[cur+1] && d[i] > d[cur+1])) return false;
        else return true;
    }
    else if (cur == n-1) {
        if ((a[i] > a[cur-1] && d[i] >= d[cur-1]) || (a[i] >= a[cur-1] && d[i] > d[cur-1])) return false;
        else return true;
    }
    else {
        if (((a[i] > a[cur-1] && d[i] >= d[cur-1]) || (a[i] >= a[cur-1] && d[i] > d[cur-1])) || ((a[i] > a[cur+1] && d[i] >= d[cur+1]) || (a[i] >= a[cur+1] && d[i] > d[cur+1])))
            return false;
        else return true;
    }
}

