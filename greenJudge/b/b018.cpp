#include<iostream>
#include<string.h>
using namespace std;
char input_L[120], input_W[120];
int L[120], W[120], result[240] = {0};
int input_L_len, input_W_len, result_len;
void num_solve(){
    cin >> input_L >> input_W;
    input_L_len = strlen(input_L);
    input_W_len = strlen(input_W);
    for(int i = 0; i < input_L_len; i++){
        L[i] = input_L[input_L_len - i - 1] - '0';
    }
    for(int i = 0; i < input_W_len; i++){
        W[i] = input_W[input_W_len - i - 1] - '0';
    }
}

void multiplication(){
    num_solve();
    for(int i = 0; i < input_L_len; i++){
        for(int j = 0; j < input_W_len; j++){
            result[i + j] += L[i] * W[j];
            if(result[i + j] > 9){
                result[i + j + 1] += result[i + j] / 10;
                result[i + j] %= 10; 
            }
        }
    }
    result_len = input_L_len + input_W_len;
    for(int i = result_len - 1; i != -1; i--)
        if(i != result_len - 1 || result[result_len - 1] != 0)
            cout << result[i];
}
void _factorial_multiplication(){
    int N, temp, counter = 0, mult_0_len, mult_1_len;
    char number[6], mult_0[60], mult_1[3000];
    mult_1[0] = 1;
    cin >> N;
    temp = N;
    for(int num = 1; num <= N; num++){
        temp = num;
        counter = 0;
        while (temp != 0)
        {
            number[counter] = temp % 10;
            temp /= 10;
            counter ++;
        }
        if(num % 2 == 0){
            for(int i = 0; i < input_L_len; i++){
                for(int j = 0; j < input_W_len; j++){
                    result[i + j] += L[i] * W[j];
                    if(result[i + j] > 9){
                        result[i + j + 1] += result[i + j] / 10;
                        result[i + j] %= 10;
                    }
                }
            }
        }
        else{

        }
    }
}
void add(){
    num_solve();
    if(input_L_len > input_W_len){
        for(int i = 0; i < input_L_len; i++){
            if(i <= input_W_len - 1)
                result[i] += L[i] + W[i];
            else
                result[i] += L[i];
            if(result[i] > 9){
                result[i + 1] ++;
                result[i] -= 10;
            }
        }
        result_len = input_L_len + 1;
    }
    else{
        for(int i = 0; i < input_W_len; i++){
            if(i <= input_L_len - 1)
                result[i] += L[i] + W[i];
            else
                result[i] += W[i];
            if(result[i] > 9){
                result[i + 1] ++;
                result[i] -= 10;
            }
        }
        result_len = input_W_len + 1;
    }
    for(int i = result_len - 1; i != -1; i--)
        if(i != result_len - 1 || result[result_len - 1] != 0)
            cout << result[i];
}
int main(){
    add();
    return 0;
}