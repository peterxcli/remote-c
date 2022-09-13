#include<iostream>
using namespace std;
int f(int N);
int _counter = 0;
int main(){
    int i;
    cin >> i;
    cout << f(i) << " ";
    printf("%d", _counter);
}

int f(int N){
    _counter ++;
    if(N == 0)
		return 0;
    else if(N == 1)
        return 1;
    else
		return f(N - 1) + f(N - 2);
}
