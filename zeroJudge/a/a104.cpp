#include<iostream>
#include<string.h>
using namespace std;
//#define IO ios::sync_with_stdio(0);cin.tie(0);
int main(){
    int n , sort[1000], temp;
    while (cin >> n)
    {   
        for(int i = 0; i < n; i++)
            cin >> sort[i];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(sort[i] > sort[j]){
                    temp = sort[i];
                    sort[i] = sort[j];
                    sort[j] = temp;
                }
            }
        }
        for(int i = 0; i < n; i++)
            cout << sort[i] << " ";
        cout << '\n';
    }
}