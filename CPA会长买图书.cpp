#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,m,res1,res2;
struct node
{
	int c,v;
	double p;
}s[10010];
bool cmp(node x,node y)
{
	return x.p>y.p;
}
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		res1=res2=0;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i].c>>s[i].v;
			s[i].p=s[i].v/s[i].c;
		}
		sort(s+1,s+1+n,cmp);
		for(int i=1;i<=m;i++)
		{
			res1+=s[i].v;
			res2+=s[i].c;
		}
		cout<<res1/res2<<endl;
	}
	return 0;
}