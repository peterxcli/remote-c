#include <algorithm>

#include <iostream>

using namespace std;

int N_site[50001]; //紀錄服務點位置

int try_1(int R, int N, int K) {
    int num = 0; //num紀錄架設的基地台數,不能超過K
    int site, i; // site紀錄直徑所到範圍
    for (i = 0; i < N;) {

        site = N_site[i] + R; //一個一個直徑慢慢擴大服務範圍

        num += 1; // 增加一個基地台

        if (num > K) // 基地台數超出K -> 不合格 (半徑太小->擴大)

            return 0;

        if (N_site[N - 1] <= site) // 服務範圍到最後的服務點,且有直徑內縮(方向<-)可能(直徑太大)

            return 1;

        while (N_site[i] <= site) //尋找下一個服務點,且超出目前基地台的服務範圍
            i++;
    }
}

int main() {

    cin.tie(0);

    ios_base::sync_with_stdio(0);

    int r, R, r_R, N, K, i; // r_R 是 r 與 R 的中間值 ( r->min , R->max )
    while (cin >> N >> K) {
        for (i = 0; i < N; i++) cin >> N_site[i];
        sort(N_site, N_site + N);
        R = N_site[N - 1] - N_site[0]; //最大直徑
        if (K != 1) {
            r = 1; //最小直徑
            while (try_1(R - 1, N, K)) {
                r_R = (r + R) / 2;
                if (try_1(r_R, N, K)) //直徑縮小
                    R = r_R;
                else
                    r = r_R + 1; // 擴大直徑
                if (r == R) //兩直徑重和
                    break;
            }
        }

        cout << R << '\n';
    }
}
