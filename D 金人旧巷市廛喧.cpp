#include <bits/stdc++.h>
using namespace std;
#define debug cout<<"!!!"<<endl;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
#define ll long long
const int inf = 1<<30;
const int N = 2001,M = 50;
int n,m,k,a[M][M],idx1[M][M],idx2[M][M];
ll val[N][N],cost[N][N],s,t, mincost=0;
ll pre[N],flow[N],dis[N],vis[N];
vector<int> g[N];
int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0}; 
 
 
int spfa(){
    FOR(i,1,n) dis[i] = inf; //离s点距离，初始是inf
    FOR(i,1,n) pre[i] = 0; //记录前驱，0表示一开始没有前驱
    dis[s] = 0; flow[s] = inf; vis[s] = 1; //超级原点的初始设置
    queue<int> q; q.push(s); //队列中放入原点
    while(q.size()){
        int u = q.front(); q.pop();
        vis[u] = 0; //出队，vis标记为0
        for(int v:g[u]){
            if(val[u][v] <= 0) continue; //流量<=0，实际上不连通
            if(dis[v] <= dis[u]+cost[u][v]) continue; //松弛失败，不做任何操作
            dis[v] = dis[u]+cost[u][v]; //进行松弛，更新距离
            pre[v] = u; //记录前驱（为了服务于mcmf函数，要记录路径）
            flow[v] = min(flow[u], val[u][v]); //记录可行的最大流量（val的前缀最小）
            if(!vis[v]) q.push(v), vis[v]=1; //当前点进入队列
        }
    }
    if(dis[t] == inf || dis[t]>=0) return 0; //如果无法到终点，或者到终点不赚钱或亏钱了，那以后就都不继续走了（证明略）
    //重点！！！dis[t]>=0就是【最小费用可行流】比起【最小费用最大流】需要加的唯一一句代码！！！
    else return 1; //能到终点，还能赚钱，这次走比不走好
}
void mcmf(){
    while(spfa()){
        int now = t;
        //maxflow += flow[t]; 记录最大流（这里其实跑的不是最大流，这个值没有意义，仅作为板子参考）
        mincost += flow[t]*dis[t]; //flow是本次流量，dis是这一条路上的【单位流量的费用】的总和
        while(now!=s){ //从终点一路往前，更新流量的信息
            val[pre[now]][now] -= flow[t]; //正向路，流量减少
            val[now][pre[now]] += flow[t]; //反向路，流量增加
            now = pre[now]; //往前走
        }
    }
}
 
int get(int x,int y,int res){
    x--,y--;
    if(res == 1 )return (x*m+y+1);
    else return n*m+x*m+y+1;
}
 
 
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>n>>m>>k; 
 
    rep(i,1,n)
        rep(j,1,m)
            cin >> a[i][j];
 
    rep(i,1,k){
        int x,y;cin >> x >> y;
        idx1[x][y] = 1;
    }
    rep(i,1,k){
        int p,q;cin >> p >> q;
        idx2[p][q] = 1;
    }
    // rep(i,1,n){
    //     rep(j,1,m){
    //         cout << get(i,j,1) << " ";
    //     }
    //     cout << endl;
    // }
    // rep(i,1,n){
    //     rep(j,1,m){
    //         cout << get(i,j,2) << " ";
    //     }
    //     cout << endl;
    // }
 
    rep(i,1,n){
        rep(j,1,m){
 
            
            int u = get(i,j,1),v = get(i,j,2);
 
            g[u].push_back(v);
            g[v].push_back(u);
            val[u][v] = 1; //注意只有单向流量
            if(a[i][j] == 1){
                    cost[u][v] = 0;
                    cost[v][u] = 0;
            }
            else{
                    cost[u][v] = 1;
                    cost[v][u] = -1;
            }
 
            rep(z,0,3){
                int xx = i+dx[z],yy = j + dy[z];
                if(xx < 1 || xx > n || yy < 1 || yy > m)continue;
                if(a[xx][yy] == -1)continue;
 
                int u1 = get(xx,yy,1);
                g[v].push_back(u1);
                g[u1].push_back(v);
 
                val[v][u1] = 1;
                cost[v][u1] = 0;
                cost[u1][v] = 0;
            }
 
        }
    }
 
    s=0; t=2*n*m+1; //超级原点和终点
    rep(i,1,n){
        rep(j,1,m){
            if(idx1[i][j]){
                int u = get(i,j,1);
                g[s].push_back(u); 
                 g[u].push_back(s); 
 
                val[s][u] = 1; 
                cost[s][u] = 0; 
                cost[u][s] = 0;
            }
        }
    }
    rep(i,1,n){
        rep(j,1,m){
            if(idx2[i][j]){
                int u = get(i,j,2);
                g[u].push_back(t);
                g[t].push_back(u); 
 
                val[u][t] = 1; 
                cost[u][t] = -100; 
                cost[t][u] = 100;
            }
        }
    }
 
    n = t;
    mcmf(); //跑mcmf
    cout<<-1*mincost<< endl; //输出最大费用可行流大小，注意乘上-1（因为代码里跑的是最小费用可行流）
}