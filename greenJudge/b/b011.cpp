/**********************************************************************************/  
/*  Problem: b011 "字裡玄機" from 字串處理-字元處理                                           */  
/*  Language: C++                                                                 */  
/*  Result: AC (4ms, 183KB) on ZeroJudge                                          */  
/*  Author: pinglunliao at 2019-10-17 10:27:44                                    */  
/**********************************************************************************/  
  
#include <iostream>  
#include <cmath>  
#include <iomanip>  
  
using namespace std;  
  
int main()  
{  
    string str;  
    int strLen;  
    int total = 0, num = 0;  
  
    for(int i = 0; i < 3; i++)  
    {  
        cin >> str;  
        strLen = str.length();  
  
        num = 0;  
        for(int j = 0; j < strLen; j++)  
            if(isdigit(str[j]))  
                num = num * 10 + (str[j] - '0');  
  
        total += num;  
    }  
  
    cout << total << endl;  
    return 0;  
}  