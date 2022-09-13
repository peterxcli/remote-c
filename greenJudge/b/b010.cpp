/**********************************************************************************/  
/*  Problem: b010 "編碼破解" from 字串應用-字元處理                                           */  
/*  Language: C++                                                                 */  
/*  Result: AC (3ms, 180KB) on ZeroJudge                                          */  
/*  Author: pinglunliao at 2019-10-16 22:17:32                                    */  
/**********************************************************************************/  
  
#include <iostream>  
#include <cmath>  
#include <iomanip>  
  
using namespace std;  
  
int main()  
{  
    string str;  
    cin >> str;  
  
    int strLen = str.length();  
    for(int i = 0; i < strLen; i++)  
        str[i] = char( (str[i] - 'A' + 24) % 26 + 'A');  
  
    cout << str << endl;  
    return 0;  
}
