#include <bits/stdc++.h>
using namespace std;
int f[2][200010];
struct node
{
	int x,y;
	int p1,p2;
}s[400020];
bool cmp(node xx,node yy)
{
	if(xx.x!=yy.x) return xx.x<yy.x;
	else
	return xx.y<yy.y;
}
int n,m,cnt;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[++cnt].x;
		cin>>s[cnt].y;
		s[cnt].p1=0;
		s[cnt].p2=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>s[++cnt].x;
		cin>>s[cnt].y;
		s[cnt].p1=1;
		s[cnt].p2=i;
	}
	sort(s+1,s+1+cnt,cmp);
	for(int i=2;i<=cnt;i++)
	{
		if(s[i].x==s[i-1].x&&s[i].p1!=s[i-1].p1)
		{
			f[s[i-1].p1][s[i-1].p2]=1;
			f[s[i].p1][s[i].p2]=1;
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		swap(s[i].x,s[i].y);
	}
	sort(s+1,s+1+cnt,cmp);
	for(int i=2;i<=cnt;i++)
	{
		if(s[i].x==s[i-1].x&&s[i].p1!=s[i-1].p1)
		{
			f[s[i-1].p1][s[i-1].p2]=1;
			f[s[i].p1][s[i].p2]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<f[0][i];
	}
	cout<<endl;
	for(int i=1;i<=m;i++)
	{
		cout<<f[1][i];
	}
	cout<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}