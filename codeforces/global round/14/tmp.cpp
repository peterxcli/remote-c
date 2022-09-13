#include <iostream>
long long int num[67][67][2]={0};  
//num[i][j][k]
//i:有i個櫃子 
//j:確定j個櫃子是安全的 
//k:最上層是1:lock,0:unlock 
using namespace std;
int main() {
  num[1][1][1]=1;num[1][0][0]=1;
  int n,s;
  for(int i=2;i<66;i++){
    for(int j=0;j<=i;j++){
      num[i][j][0]+=num[i-1][j+1][1]+num[i-1][j][0];
      if (j>0)                
      num[i][j][1]+=num[i-1][j-1][0]+num[i-1][j-1][1];     
    }       
  }
  while(cin >> n >> s){
    if ((n<0)&&(s<0)) break;
    cout << num[n][s][0]+num[n][s][1] << endl;                     
  } 
  //system("pause");
}
