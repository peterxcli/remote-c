/**********************************************************************************/  
/*  Problem: b002 "找最大值 (**)" from 陣列應用-掃描                                        */  
/*  Language: C++                                                                 */  
/*  Result: AC (3ms, 188KB) on ZeroJudge                                          */  
/*  Author: pinglunliao at 2019-10-16 10:14:19                                    */  
/**********************************************************************************/  
  
#include <iostream>  
#include <cmath>  
#include <iomanip>  
  
using namespace std;  
  
int main()  
{  
    int n, m, idx = 0;  
    int iArray[10];  
  
    cin >> n;  
  
    for(int i = 0; i < n; i++)  
        cin >> iArray[i];  
  
    m = iArray[idx];  
    while(--n)  
    {  
        if(m < iArray[n])  
        {  
            m = iArray[n];  
            idx = n;  
        }  
    }  
  
    cout << (idx + 1) << " " << m << endl;  
    return 0;  
} 