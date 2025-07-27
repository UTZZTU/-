#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int N=1e5+5;
int n,m,k,p,w[N],st,fin;
vector<int>sides[N];
bool vis[N];
struct node{
    int id,sp,v;
};
int ans=0,msp=0x3f3f3f3f; 
void bfs()
{
    queue<node>q;
    if (p==1)
        q.push({st,1,w[st]});
    else q.push({st,1,0});
    vis[st]=true;
    
    while (q.size())
    {
        node f=q.front();q.pop();
        if (f.id==fin)
        {
            if (f.sp>msp)
                break;
            else 
            {
                msp=f.sp,ans=max(ans,f.v);
                continue;
            }
        }
        for (int i=0;i<sides[f.id].size();i++)
        {
            int ch=sides[f.id][i];
            if (vis[ch] && ch!=fin)
                continue;
            vis[ch]=true;
            
            int v=f.v;
            int sp=f.sp+1;
            if (p==k && sp%k==0)
                v+=w[ch];
            else 
                if (sp%k==p)
                    v+=w[ch]; 
            q.push({ch,sp,v});
        }
    }
}
int main()
{
    cin>>n>>m>>k>>p;
    for (int i=1;i<=n;i++)
        cin>>w[i];
    for (int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        sides[a].push_back(b),sides[b].push_back(a);
    }
    cin>>st>>fin;
    bfs();
    cout<<ans<<endl;
    return 0;
}