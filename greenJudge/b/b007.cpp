/**********************************************************************************/  
/*  Problem: b007 "倒背如流 (**)" from 字串應用-字元拆解                                      */  
/*  Language: C++                                                                 */  
/*  Result: AC (3ms, 168KB) on ZeroJudge                                          */  
/*  Author: pinglunliao at 2019-10-16 18:59:40                                    */  
/**********************************************************************************/  
  
#include <iostream>  
#include <cmath>  
#include <iomanip>  
  
using namespace std;  
  
int main()  
{  
    string name;  
    cin >> name;  
  
    int len = name.length();  
    for(int i = len - 1; i >= 0; i--)  
        cout << name[i];  
  
    return 0;  
}  