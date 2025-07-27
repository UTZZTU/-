#include<set>
#include<map>
#include<queue>
#include<stack>
#include<ctime>
#include<deque>
#include<cmath>
#include<vector>
#include<string>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>
#define REP(i,s,t) for(int i=(s);i<=(t);i++)
#define REP2(i,t,s) for(int i=(t);i>=s;i--)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;

const int maxn=20005;
int T;
int n,m;
struct TwoSAT
{
    int n;
    vector<int>G[maxn*2];
    bool mark[maxn*2];
    int S[maxn*2],c;
    bool dfs(int x)
    {
        if(mark[x^1])
        {
            return false;
        }
        if(mark[x])
        {
            return true;
        }
        mark[x]=true;
        S[c++]=x;
        for(int i=0;i<G[x].size();i++)
        {
            if(!dfs(G[x][i]))
            {
                return false;
            }
        }
        return true;
    }
    void init(int n)
    {
        this->n=n;
        for(int i=0;i<n*2;i++)
        {
            G[i].clear();
            memset(mark,0,sizeof(mark));
        }
    }
    void add_clause(int x,int xval,int y,int yval)
    {
        x=x*2+xval;
        y=y*2+yval;
        G[x^1].push_back(y);
        G[y^1].push_back(x);
    }
    bool solve()
    {
        for(int i=0;i<n*2;i+=2)
        {
            if(!mark[i]&&!mark[i+1])
            {
                c=0;
                if(!dfs(i))
                {
                    while(c>0)
                    {
                        mark[S[--c]]=false;
                    }
                    if(!dfs(i+1))
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    void fuck()
    {
        vector<int>ans;
        ans.clear();
        for(int i=0;i<n*2;i+=2)
        {
            if(mark[i+1])
            {
                //printf("%d\n",i/2+1);
                ans.push_back(i/2+1);
            }
        }
        printf("%d",ans.size());
        for(int i=0;i<ans.size();i++)
        {
            printf(" %d",ans[i]);
        }
        printf("\n");
    }
}solver;
int main()
{
  #ifdef ONLINE_JUDGE
  #else
    freopen("test.in","r",stdin);
  #endif
  int ca=1;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d%d",&m,&n);
    solver.init(n);
    REP(i,1,m)
    {
        int x,y,xval,yval;
        scanf("%d%d",&x,&y);
        if(x>0)
        {
            x=x-1;
            xval=1;
        }
        else
        {
            x=(-x)-1;
            xval=0;
        }
        if(y>0)
        {
            y=y-1;
            yval=1;
        }
        else
        {
            y=(-y)-1;
            yval=0;
        }
        solver.add_clause(x,xval,y,yval);
    }
    bool flag=solver.solve();
    printf("Case %d: %s\n",ca++,flag?"Yes":"No");
    if(flag)solver.fuck();
  }
  return 0;
}