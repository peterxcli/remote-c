#include <iostream>
#include <stack>
#include <vector>
#define max_n 1005
using namespace std;
typedef pair<int,int> PII;
vector<PII> vec;
int head[max_n];
int cnt = 0;
struct edge
{
    int v;
    int nxt;
}e[max_n<<1];
void add(int u,int v)
{
    ++cnt;
    e[cnt].v = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}
int n,m;
int idx = 0;
int Bcnt;
int instack[max_n];
int dfn[max_n];
int low[max_n];
int belong[max_n];
stack<int> s;
void tarjan(int u) {
    dfn[u] = low[u] = ++idx;
    s.push(u);
    instack[u]=1;
    int v;
    for(int i = head[u];i;i=e[i].nxt) {
        v = e[i].v;
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if(instack[v]) {
            low[u] = min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]) {
        Bcnt++;
        do
        {
            v=s.top();
            s.pop();
            instack[v]=0;
            belong[v]=Bcnt;
        }while(u!=v);
    }
}
int main() {
    cin >> n;
    for(int i = 0;i<n;i++) {
        int x,y;
        cin >> x >> y;
        vec.push_back(PII(x,y));
    }
    for(int i = 0;i<n;i++) {
        for(int j = i+1;j<n;j++) {
            if(vec[i].first==vec[j].first||vec[i].second==vec[j].second) {
                add(i,j);
                add(j,i);
            }
        }
    }
    for(int i = 0;i<n;i++) {
        if(!dfn[i]) {
            tarjan(i);
        }
    }
    cout << Bcnt-1 << endl;
    return 0;
}