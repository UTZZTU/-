#include <bits/stdc++.h>
using namespace std;
int n,a,b;
bool judge(int x)
{
	int res=1;
	for(int i=1;i<=n;i++)
	{
		res*=x;
		if(abs(res)>abs(b)) return false;
	}
	return res==b;
}
void solve()
{
	cin>>a>>b>>n;
	if(a==0)
	{
		if(b!=0) cout<<"No solution"<<endl;
		else if(b==0) cout<<"0"<<endl;
		return;
	}
	if(b%a!=0)
	{
		cout<<"No solution"<<endl;
		return;
	} 
	b/=a;
	if(n%2==0&&b<0)
	{
		cout<<"No solution"<<endl;
		return;
	}
	for(int i=0;;i++)
	{
		if(i>abs(b)) break;
		if(judge(i))
		{
			cout<<i<<endl;
			return;
		}
	}
	for(int i=-1;;i--)
	{
		if(abs(i)>abs(b)) break;
		if(judge(i))
		{
			cout<<i<<endl;
			return;
		}
	}
	cout<<"No solution"<<endl;
}
int main ()
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