#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 4e5 + 5, maxm = 4e5 + 5;

vector<vector<int>> edges;     //存原图的边
vector<vector<int>> edges_scc; //存强连通分量缩点之后的边
stack<int> stk;
vector<int> dfn;    //dfn[u]:u点的dfs序
vector<int> low;    // low[u]:u点经过最多一条非树边可达的最小dfs序结点的dfs序
vector<int> idx;    // idx：每个点所属的强连通分量编号
vector<bool> instk; //instk：是否在栈中
int dfsn, cnt_scc;  //dfsn：当前点的dfs序，cnt_scc：强连通分量的数量

vector<bool> isloop, isloop_scc; //标记点是否有自环和强连通分量内是否有环

vector<int> deg; //degree,存每个结点的入度，在存图的时候需要录入数据
vector<int> dp;  //dp[i]表示第i个强连通分量内的点的路径数

void tarjan(int u) {
    low[u] = dfn[u] = ++dfsn; //按dfs序赋值dfn以及low(每个结点至少可达自己)
    instk[u] = 1;
    stk.push(u);            // 进栈
    for (auto v : edges[u]) //遍历当前点的所有边
    {

        if (!dfn[v]) //未访问过v，则为v为u的儿子结点
        {
            tarjan(v);                    //先递归儿子结点
            low[u] = min(low[u], low[v]); //用儿子结点的low值更新父亲结点的low值
        } else if (instk[v])              //已经访问过v，且v在栈中，即u可达v
            low[u] = min(low[u], dfn[v]); //用v的dfs序的值更新u的low值
    }
    if (low[u] == dfn[u]) //若当前节点的low值计算完后dfn值等于low值,则当前节点为一个强连通分量的根结点
    {
        int top;
        cnt_scc++;   //强连通分量数量+1
        int num = 0; //统计强连通分量内点的个数
        do {
            num++;
            top = stk.top();
            stk.pop();                  //取栈首结点并弹栈
            instk[top] = 0;             //标记此节点已不在栈中
            idx[top] = cnt_scc;         // 记录所属的强连通分量
            if (isloop[top] || num > 1) //若当前点有自环或者当前强连通分量内点的个数大于1，则强连通分量内有环
                isloop_scc[cnt_scc] = 1;
        } while (top != u); //直到弹出u才停止
    }
}
void findscc(int n) {
    for (int i = 1; i <= n; ++i) //tarjan求强连通分量
        if (!dfn[i])
            tarjan(i);
    for (int u = 1; u <= n; ++u)  //遍历所有点 //强连通分量缩点
        for (auto v : edges[u])   //遍历当前点的所有边
            if (idx[u] != idx[v]) //若当前点与其所连接的点不属于同一强连通分量,则当前边为缩点之后的一条边
            {
                edges_scc[idx[u]].push_back(idx[v]);
                deg[idx[v]]++; //统计强连通分量缩点后的入度
            }
}

void toposort(int n) {
    queue<int> q;
    for (int i = 1; i <= n; ++i) //先找到入度为0的点
    {
        if (deg[i] == 0)
            q.push(i); //加入队列
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : edges_scc[u]) { //遍历入度为0的点的边
            deg[v]--;                 //更新入度
            if (deg[v] == 0)          //若出现了新的入度为0的点
                q.push(v);            //加入队列

            if (dp[u] != 0) //若当前强连通分量从点1不可达，则跳过
            {
                if (dp[u] == -1 || isloop_scc[v]) //若当前强连通分量路径数为无穷大或下一个强连通分量内有环
                    dp[v] = -1;
                else if (dp[v] != -1) {
                    if (dp[u] == 2 || dp[v]) //若当前强连通分量路径数有多条或下一个强连通分量已经有至少一条路径
                        dp[v] = 2;
                    else //若当前强连通分量路径只有一条且下一个强连通分量路径数为0
                        dp[v] = 1;
                }
            }
        }
    }
}

void init(int n) {
    edges = vector<vector<int>>(n + 5);
    edges_scc = vector<vector<int>>(n + 5);
    stk = stack<int>();
    dfn = vector<int>(n + 5);
    low = vector<int>(n + 5);
    idx = vector<int>(n + 5);
    instk = vector<bool>(n + 5);
    cnt_scc = 0, dfsn = 0;
    isloop = vector<bool>(n + 5);
    isloop_scc = vector<bool>(n + 5);
    deg = vector<int>(n + 5);
    dp = vector<int>(n + 5);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, m;
    cin >> t;
    while (t--) {
        int u, v;
        cin >> n >> m;
        init(n);
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            edges[u].push_back(v);
            if (v == u) //有自己指向自己的边，则有自环
                isloop[v] = 1;
        }
        findscc(n);
        dp[idx[1]] = (isloop_scc[idx[1]] ? -1 : 1); //1号点所在的强连通分量的路径数预先给定
        toposort(cnt_scc);
        for (int i = 1; i <= n; i++)
            cout << dp[idx[i]] << " ";
        cout << endl;
    }
}