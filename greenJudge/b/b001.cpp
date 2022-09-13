/**********************************************************************************/  
/*  Problem: b001 "最後倒數 (**)" from 陣列應用-記錄                                        */  
/*  Language: C++                                                                 */  
/*  Result: AC (4ms, 180KB) on ZeroJudge                                          */  
/*  Author: pinglunliao at 2019-10-16 10:08:25                                    */  
/**********************************************************************************/  
  
#include <iostream>  
#include <cmath>  
#include <iomanip>  
  
using namespace std;  
  
int main()  
{  
    int n;  
    int iArray[10];  
  
    cin >> n;  
  
    for(int i = 0; i < n; i++)  
        cin >> iArray[i];  
  
    while(n > 0)  
    {  
        cout << iArray[n-1] << " ";  
        n--;  
    }  
  
    return 0;  
}  