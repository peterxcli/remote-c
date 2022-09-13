// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// int main() {
//     char monkey_input[100000], target_str[100000];
//     int monkey_input_len, target_str_len, counter;
//     int StillNotFind, temp;
//     scanf("%s %s", target_str, monkey_input);
//     counter = 0;
//     target_str_len = strlen(target_str);
//     monkey_input_len = strlen(monkey_input);
//     for(int i = 0; i < target_str_len; i++){ // a aa
//         for(int j = temp; j < monkey_input_len; j++){
//             if(target_str[i] == monkey_input[j]){
//                 target_str[i] = ',';
//                 monkey_input[j] = ',';
//                 //printf("%c", target_str[i]);
//                 counter++;
//                 temp = j;
//                 break;
//             }
//         }
//     }
//     if(counter == target_str_len){
//         printf("YES");
//     }
//     else{
//         printf("NO");
//     }   
// }



#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word, monkey;
    cin >> word >> monkey;
    for (int i = 0; i < monkey.size(); ++i) {
        int counter = 0;
        for (int j = 0; j < word.size(); ++j) {
            if (monkey[i] != word[j]) {
                counter++;
            }
        }
        if (counter == word.size()){
            monkey.erase(i, 1);
            i--;
        }

    }
    if (word == monkey)
        cout << "YES";
    else
        cout << "NO";
}