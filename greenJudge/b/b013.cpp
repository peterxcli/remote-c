#include<iostream>
#include<string.h>
using namespace std;
int main(){
    char a[3][110];
    for(int i = 0; i < 3; i++)
        cin.getline(a[i], 105);
    cout << a[2] << "\n" << a[0] << "\n" << a[1];
}