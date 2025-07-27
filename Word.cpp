#include <bits/stdc++.h>
using namespace std;
string a[2020],s,t;
vector<string> vec;
vector<string> golbal;
int minn=0x3f3f3f3f,n,m,vis[2020];
bool check(string u,string v)
{
	int js=0;
	for(int i=0;i<u.size();i++)
	if(u[i]!=v[i])
	js++;
	return js==1;
}
void dfs(string u,int ans)
{
	if(check(u,t))
	{
		if(ans<minn)
		{
			minn=ans;
			vec=golbal;
		}
		return;
	}
	int pos=0;
	for(int i=1;i<=n;i++)
	{
		if(check(u,a[i])&&!vis[i])
	{
		pos=1;
		vis[i]=1;
		golbal.push_back(a[i]);
		dfs(a[i],ans+1);
		vis[i]=0;
		golbal.pop_back();
	}
	}
	if(pos==0)
	return;
}
int main ()
{
	scanf("%d %d",&n,&m);
	getchar();
	for(int i=1;i<=n;i++)
	cin>>a[i];
	cin>>s>>t;
	if(s==t)
	{
		cout<<0<<endl;
		cout<<s<<endl<<s;
		return 0;
	}
	golbal.push_back(s);
	dfs(s,0);
	if(minn==0x3f3f3f3f)
	cout<<-1;
	else
	{
		cout<<minn<<endl;
		for(int i=0;i<vec.size();i++)
		cout<<vec[i]<<endl;
		cout<<t;
	}
	return 0;
}