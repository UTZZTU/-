#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int a[50],cnt,tt[50]={-1};
void dfs(int level,vector<int> vec,int sum,int xx)
{
	if(level==9)
	{
		if(sum==xx)
		{
			jj(vec)
		}
		else
		{
			return;
		}
	}
}
int num(int x)
{
	if(tt[x]!=-1) return tt[x];
	vector<int> vec;
	dfs(1,vec,sum,x);
	return tt[x];
}
void solve()
{
	cnt=1;
	for(int i=1;i<=32;i++)
	{
		cin>>a[i];
		if(i>=2)
		{
			if(a[i]>a[1]) cnt++;
		}
	}
	cout<<num(cnt)<<endl;
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