#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,W,w[1000010],d[1000010],f[1000010][21],maxx=-1e18;
void solve()
{
	cin>>n>>W;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		w[i]+=w[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
		d[i]+=d[i-1];
		f[i][0]=d[i];
	}
	int b=(int)(log(n)/log(2));
	for(int j=1;j<=b;j++)
        for(int i=1;i<=n-(1<<j)+1;i++)
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    for(int i=1;i<=n;i++)
    {
    	int pos=lower_bound(w+1,w+1+n,w[i-1]+W)-w;
    	if(pos==n+1) continue;
    	int l=pos,r=n;
    	int p=(int)(log(r-l+1)/log(2));
    	int mx=max(f[l][p],f[r-(1<<p)+1][p]);
    	maxx=max(maxx,mx-d[i-1]);
	}
	cout<<maxx<<endl;
}
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}