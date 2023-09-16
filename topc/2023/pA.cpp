#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <ctime>
using namespace std;
// void debug_out(){cerr<<"]\n"<<flush;}
// template<typename Head,typename... Tail>void debug_out(Head H,Tail... T){cerr << H;if(sizeof...(T))cerr<<", ";debug_out(T...);}
// #define debug(...) cerr<<"LINE("<<__LINE__<<") : ["<<#__VA_ARGS__<<"] = [";debug_out(__VA_ARGS__)
//#define endl '\n'
// #define int long long

bool isDAteTooLate(int d, int m, int y) {
    struct tm t = {0};
    t.tm_mday = 21;
    t.tm_mon = 9;
    t.tm_year = 2023 - 1900;

    time_t target = mktime(&t);

    target -= 35 * 24 * 60 * 60;

    struct tm t2 = {0};
    t2.tm_mday = d;
    t2.tm_mon = m - 1;
    t2.tm_year = y - 1900;

    time_t now = mktime(&t2);
    return now > target;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int d, m, y;
    char c;
    cin >> y >> c >> m >> c >> d;

    if (isDAteTooLate(d, m, y)) {
        cout << "TOO LATE" << endl;
    } else {
        cout << "GOOD" << endl;
    }
    return 0;
}

