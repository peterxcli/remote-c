#include <iostream>
using namespace std;
char c[7]={'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int cc[7]={1, 5, 10, 50, 100, 500, 1000};
string ccc[13]={"I", "IV", "V","IX","X","XL","L","XC","C","CD","D","CM","M"};
int cccc[13]={1,4,5,9,10,40,50,90,100,400,500,900,1000};

int ch(char a){
    for(int b = 0; b < 7; b++)
        if(a == c[b])
            return b;
}

int in(string a){
    int d = 0;
    for(int b = 0; b < a.size(); b++){
        if(!(b+1 == a.size()) && ch(a[b]) < ch(a[b + 1]))
            d -= cc[ch(a[b])];
        else
            d += cc[ch(a[b])];
        }
    return d;
}

void out(int a){
    if(a == 0)
        cout << "ZERO" <<endl;
    else{
        string b = "";
        for(int d = 12; d >= 0; d--){
            for(int e = 0; e < a / cccc[d]; e++)
                b += ccc[d];
            a %= cccc[d];
        }
        cout<<b<<endl;
    }

}

int main(){
    string a,b;
    while(cin >> a && a[0] != '#'){
        cin >> b;
        out(abs(in(a) - in(b)));
    }
}