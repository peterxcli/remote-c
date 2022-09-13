/**********************************************************************************/  
/*  Problem: b005 "熱門點播" from 陣列應用-計數                                             */  
/*  Language: C++                                                                 */  
/*  Result: AC (4ms, 188KB) on ZeroJudge                                          */  
/*  Author: pinglunliao at 2019-10-16 18:53:55                                    */  
/**********************************************************************************/  
  
#include <iostream>  
#include <cmath>  
#include <iomanip>  
  
using namespace std;  
  
int main()  
{  
    int n, m = 0, idx = 0;  
    int maxCnt = 0, maxIdx;  
  
    int num[20] = {0};  
    int cnt[20] = {0};  
  
    cin >> n;  
  
    for(int i = 0; i < n; i++)  
    {  
        int flag = 0;  
        cin >> m;  
        for(int j = 0; j < n; j++)  
            if(num[j] == m)  
            {  
                cnt[j] += 1;  
                flag = 1;  
  
                if(cnt[j] > maxCnt)  
                {  
                    maxIdx = j;  
                    maxCnt = cnt[j];  
                }  
  
                break;  
            }  
  
        if(flag == 0)  
        {  
            num[idx] = m;  
            cnt[idx] = 1;  
            idx++;  
        }  
    }  
  
    cout << num[maxIdx] << " " << cnt[maxIdx] << endl;  
  
    return 0;  
}  
