#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define N (int)(1e5+15)

vector<int> son[N];
int n,m,w[N],f[N];
int cmp(int x,int y)
{return f[y]-w[y]<f[x]-w[x];}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("check.in","r",stdin);
    // freopen("check.out","w",stdout);
    cin >> n;
    for(int i=2,u; i<=n; i++)
        cin >> u,son[u].push_back(i);
    for(int i=1; i<=n; i++) cin >> w[i];
    for(int i=n; i>=1; i--)
    {
        sort(son[i].begin(),son[i].end(),cmp);
        int sum=0;
        for(int v : son[i])
            f[i]=max(f[i],f[v]+sum),sum+=w[v];
        f[i]=max(f[i],sum+w[i]);
    }
    for(int i=1; i<=n; i++)
        cout << f[i] << " \n"[i==n];
    return 0;
}
