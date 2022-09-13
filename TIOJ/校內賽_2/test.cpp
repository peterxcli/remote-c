#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[100],d[100];
int L[100];
int main(){
    int n, i, j, k, win, next, max;
    while(scanf("%d", &n) != EOF){
        max = 0;
        for(int i = 0; i < n; i++){
            scanf("%d %d", &a[i], &d[i]);
        }
        for(i = 0; i < n; ) {
            win = 0;
            j = i - 1;
            while(j >= 0) { 
                if (((a[i] > a[j]) && (d[i] >= d[j])) || (a[i] >= a[j]) && (d[i] > d[j])){
                    win = win + L[j] + 1;
                    j = j - L[j]-1;
                }
                else{
                    break;
                }
            }
            L[i] = win; 
            j = i + 1;
            while(j < n){ 
                if (((a[i] > a[j]) && (d[i] >= d[j])) || (a[i] >= a[j]) && (d[i] > d[j])){
                    win++; 
                    j++;
                }
                else{
                    next = j; 
                    break;
                } 
            }
            if (max < win) max = win;
            if (j == n) break;
                i = next;
        }
        printf("%d\n", max);
    }
}