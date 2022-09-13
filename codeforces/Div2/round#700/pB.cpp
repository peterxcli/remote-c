#include <bits/stdc++.h>
#define inf (long long)1e18
#define MAXN 100010
// #define inf (int)1e9
#define int long long
using namespace std;
typedef long long ll;

struct Hero{
    int attack;
    int health;
}hero;

struct Monster{
    int attack;
    int health;
}monsters[MAXN];

bool cmp (Monster a, Monster b) {
    // return (a.health/hero.attack*a.attack+(a.health%hero.attack)*a.attack) < (b.health/hero.attack*b.attack+(b.health%hero.attack)*b.attack); 
    return a.attack < b.attack; 
}

void slove() {
    cin >> hero.attack >> hero.health;
    int n, flag = 1;
    cin >> n;
    for (int i = 0 ; i < n; i++) cin >> monsters[i].attack;
    for (int i = 0 ; i < n; i++) cin >> monsters[i].health;
    sort(monsters, monsters+n, cmp);
    for (int i = 0 ; i < n; i++) {
        if (i == n-1) {
            hero.health -= (monsters[i].health/hero.attack-1)*monsters[i].attack;
            monsters[i].health -= (monsters[i].health/hero.attack-1)*hero.attack;
            if (hero.health <= 0) flag = 0;
            while(monsters[i].health > 0) {
                monsters[i].health -= hero.attack;
                hero.health -= monsters[i].attack;
                if (hero.health <= 0 && monsters[i].health > 0) {
                    flag = 0;
                }
            }
            break;
        }
        hero.health -= (monsters[i].health/hero.attack)*monsters[i].attack;
        monsters[i].health -= (monsters[i].health/hero.attack)*hero.attack;
        if (hero.health <= 0 && monsters[i].health > 0) {flag = 0;break;}
        if (monsters[i].health > 0) {
            monsters[i].health -= hero.attack;
            hero.health -= monsters[i].attack;
        }
        if (hero.health <= 0 && i != (n-1)) {
            flag = 0;
            break;
        }
        if (hero.health <= 0 && i == (n-1) && monsters[i].health > 0) {
            flag = 0;
            break;
        }
    }

    if (flag) cout << "YES\n";
    else cout << "NO\n";
}

int32_t main() {
    cin.tie(0), ios_base::sync_with_stdio(0);   
    int t;
    cin >> t;
    while(t--) {
        slove();
    }
}