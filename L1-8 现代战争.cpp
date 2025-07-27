#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,f[1010][1010],px,py,bjh[1010],bjl[1010],cnt;
struct node
{
	int x,y,w;
}s[1000010];
bool cmp(node x,node y)
{
	return x.w>y.w;
}
int main ()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>f[i][j];
			s[++cnt].x=i;
			s[cnt].y=j;
			s[cnt].w=f[i][j];
		}
	}
	sort(s+1,s+1+cnt,cmp);
	int pcnt=1;
	while(k--)
	{
		px=s[pcnt].x;
		py=s[pcnt].y;
		bjh[px]=1;
		bjl[py]=1;
		while(pcnt<=n*m&&(bjh[s[pcnt].x]||bjl[s[pcnt].y]))
		{
//			cout<<s[pcnt].w<<endl;
			pcnt++;
		}
//		cout<<s[pcnt].w<<endl;
//		for(int i=1;i<=n;i++)
//		{
//			h[i].erase(h[i].lower_bound(f[i][py]));
//		}
//		for(int i=1;i<=m;i++)
//		{
//			l[i].erase(h[i].lower_bound(f[px][i]));
//		}
//		h[px].clear();
//		l[py].clear();
	}
//	int kss=-1;
	for(int i=1;i<=n;i++)
	{
		int ks=-1;
		for(int j=1;j<=m;j++)
		{
			if(!bjh[i]&&!bjl[j])
			{
				if(ks==-1) ks=1;
				else cout<<" ";
				cout<<f[i][j];
			}
		}
		if(ks!=-1) cout<<endl;
	}
	return 0;
}
