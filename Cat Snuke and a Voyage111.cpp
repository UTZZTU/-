#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<utility>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#define EPS 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LL long long
const int MOD = 1E9+7;
const int N = 200000+5;
const int dx[] = {-1,1,0,0,-1,-1,1,1};
const int dy[] = {0,0,-1,1,-1,1,-1,1};
using namespace std;
struct Edge{
    int to;
    int next;
}edge[N];
int n,m;
int tot,head[N];
void addEdge(int from,int to){
    edge[++tot].to=to;
    edge[tot].next=head[from];
    head[from]=tot;
}
bool dfs(int s,int step){
    if(s==n&&step==2)
        return true;
    for(int i=head[s];i!=-1;i=edge[i].next){
        int to=edge[i].to;
        if(dfs(to,step+1))
            return true;
    }
    return false;
}
int main() {
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        addEdge(x,y);
    }
 
    bool flag=dfs(1,0);
    if(flag)
        printf("POSSIBLE\n");
    else
        printf("IMPOSSIBLE\n");
    return 0;
}