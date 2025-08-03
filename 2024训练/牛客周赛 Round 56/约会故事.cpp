#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,m,f[200010],hh1,mm1,hh2,mm2,t1,t2,cf[200010],q;
map<string,bool> mp;
void solve()
{
//	cin>>n>>m;
	scanf("%d%d",&n,&m);
//	for(int i=121;i<=24*60+1;i++) f[i]=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d:%d %d:%d",&hh1,&mm1,&hh2,&mm2);
		t1=hh1*60+mm1,t2=hh2*60+mm2;
		if(t1<t2)
		{
			cf[t1]++;
			cf[t2+1]--;
		}
		else
		{
			cf[t1]++;
			cf[0]++;
			cf[t2+1]--;
		}
	}
	ll res=0;
	for(int i=0;i<120;i++)
	{
		res+=cf[i];
		if(res) f[i]=1;
		else f[i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		string s;
		cin>>s;
		mp[s]=true;
	}
	cin>>q;
	while(q--)
	{
		int flag=1;
		scanf("%d:%d",&hh1,&mm1);
		t1=hh1*60+mm1;
//		cout<<"t1:"<<t1<<endl;
		if(!f[t1]) flag=-1;
		scanf("%d:%d %d:%d",&hh1,&mm1,&hh2,&mm2);
		t1=hh1*60+mm1,t2=hh2*60+mm2;
		if(t1>t2&&flag!=-1) flag=0;
		string s;
		cin>>s;
		if(mp[s]==false&&flag!=-1) flag=0;
		if(flag==1) printf("Winner xqq\n");
		else if(flag==0) printf("Joker xqq\n");
		else printf("Loser xqq\n");
	}
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