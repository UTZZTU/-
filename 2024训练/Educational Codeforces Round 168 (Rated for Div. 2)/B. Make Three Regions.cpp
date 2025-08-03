#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s,t;
int n,res,pre[200010],post[200010];
void solve()
{
	cin>>n;
	res=0;
	cin>>s>>t;
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]=='.'||t[i-1]=='.') pre[i]=1;
		else pre[i]=0;
		pre[i]+=pre[i-1];
	}
	post[n+1]=0;
	for(int i=n;i>=1;i--)
	{
		if(s[i-1]=='.'||t[i-1]=='.') post[i]=1;
		else post[i]=0;
		post[i]+=post[i+1];
	}
	for(int i=1;i<n-1;i++)
	{
		if(s[i]=='x'||t[i]=='x') continue;
		if(pre[i]&&post[i+2]&&(s[i-1]=='x'&&s[i+1]=='x'||t[i-1]=='x'&&t[i+1]=='x')) res++;
	}
	cout<<res<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}