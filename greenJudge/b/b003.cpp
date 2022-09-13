/**********************************************************************************/  
/*  Problem: b003 "資料分組 (**)" from 陣列應用-掃描                                        */  
/*  Language: C++                                                                 */  
/*  Result: AC (4ms, 188KB) on ZeroJudge                                          */  
/*  Author: pinglunliao at 2019-10-16 10:21:34                                    */  
/**********************************************************************************/  
  
#include <iostream>  
#include <cmath>  
#include <iomanip>  
  
using namespace std;  
  
int main()  
{  
    int n, m;  
    int l = 0, g = 0;  
  
    int iArray[10];  
  
    cin >> n;  
  
    for(int i = 0; i < n; i++)  
        cin >> iArray[i];  
  
    cin >> m;  
  
    while(--n >= 0)  
    {  
        if(iArray[n] > m)  
        {  
            g++;  
        }  
        else if(iArray[n] < m)  
        {  
            l++;  
        }  
    }  
  
    cout << g << " " << l << endl;  
  
    return 0;  
} 