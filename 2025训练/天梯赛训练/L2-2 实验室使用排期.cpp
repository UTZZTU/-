#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,hh,mm,ss;
int sl(int h,int m,int s)
{
	return h*3600+m*60+s;
}
struct node
{
	int q,h;
}s[2010];
bool cmp(node a,node b)
{
	return a.h<b.h;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d:%d:%d",&hh,&mm,&ss);
		int p1=sl(hh,mm,ss);
		scanf("%d:%d:%d",&hh,&mm,&ss);
		int p2=sl(hh,mm,ss);
		s[i].q=p1,s[i].h=p2;
//		cout<<p1<<" "<<p2<<endl;
	}
	sort(s+1,s+1+n,cmp);
	int dq=s[1].h,cnt=1;
	for(int i=2;i<=n;i++)
	{
		if(s[i].q>=dq)
		{
			cnt++;
			dq=s[i].h;
		}
	}
	cout<<cnt;
}
int main ()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}