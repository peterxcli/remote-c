/**********************************************************************************/  
/*  Problem: b004 "一個都不能少" from 陣列應用-標記                                           */  
/*  Language: C++                                                                 */  
/*  Result: AC (3ms, 180KB) on ZeroJudge                                          */  
/*  Author: pinglunliao at 2019-10-16 10:29:02                                    */  
/**********************************************************************************/  
  
#include <iostream>  
#include <cmath>  
#include <iomanip>  
  
using namespace std;  
  
int main()  
{  
    int n, m, idx;  
  
    int flag[21] = {0};  
  
    cin >> n >> m;  
  
    for(int i = 0; i < m; i++)  
    {  
        cin >> idx;  
        flag[idx] = 1;  
    }  
  
    for(int i = 1; i <= n; i++)  
    {  
        if(flag[i] == 0)  
            cout << i << " ";  
    }  
  
    return 0;  
}  