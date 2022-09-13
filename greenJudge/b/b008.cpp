/**********************************************************************************/  
/*  Problem: b008 "迴文 (**)" from 字串應用-字元拆解                                        */  
/*  Language: C++                                                                 */  
/*  Result: AC (4ms, 180KB) on ZeroJudge                                          */  
/*  Author: pinglunliao at 2019-10-16 19:03:36                                    */  
/**********************************************************************************/  
  
#include <iostream>  
#include <cmath>  
#include <iomanip>  
  
using namespace std;  
  
int main()  
{  
    string name;  
    cin >> name;  
  
    bool yes = true;  
    int len = name.length();  
    int halfLen = len / 2;  
  
    for(int i = 0, j = len - 1; i <= halfLen; i++, j--)  
    {  
        if(name[i] != name[j])  
        {  
            yes = false;  
            break;  
        }  
    }  
  
    if(yes == true)  
        cout << "YES" << endl;  
    else  
        cout << "NO" << endl;  
  
    return 0;  
}  
