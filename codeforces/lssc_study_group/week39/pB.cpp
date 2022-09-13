#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, arr[100005]={0}, ans = 1, cnt = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i = 1; i < n; i++) {
        if(arr[i] > arr[i-1]) {
            cnt++;
        }
        else {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    printf("%d\n", max(cnt, ans));
}