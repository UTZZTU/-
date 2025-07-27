#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
struct bd
{
    vector<int> a;
    int l;
}s[10010];
int pre[10010],ks=1;
void dfs(int n)
{
    stack<int> p;
    p.push(n);
    while(pre[n]!=n)
    {
        n=pre[n];
        p.push(n);
    }
    s[ks].l=p.size();
    while(!p.empty())
    {
        s[ks].a.push_back(p.top());
        p.pop();
    }
    ks++;
    return;
}
bool cmp(bd x,bd y)
{
    if(x.l!=y.l)
        return x.l>y.l;
    else
        return x.a<y.a;
}
int main ()
{
    int n,i,k,j,m;
    cin>>n;
    for(i=0;i<n;i++)
        pre[i]=i;
    for(i=0;i<n;i++)
    {
        cin>>k;
        for(j=1;j<=k;j++)
        {
            cin>>m;
            pre[m]=i;
        }
    }
    for(i=0;i<n;i++)
    {
        dfs(i);
    }
    sort(s+1,s+ks,cmp);
    printf("%d\n",s[1].l);
    	for(auto it=s[1].a.begin();it!=s[1].a.end();it++)
    {
        if(it!=s[1].a.begin())
            printf(" ");
        cout<<*it;
    }
    
    return 0;
}