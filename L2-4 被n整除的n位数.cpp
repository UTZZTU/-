#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a,b;
ll cnt;
void dfs(ll sum,ll pos)
{
	if(pos>n)
	{
		if(sum>=a&&sum<=b)
		{
			cout<<sum<<endl;
			cnt++;
		}
		return;
	}
	if(pos==10)
	{
		dfs(sum*10,pos+1);
	}
	else if(pos==5)
	{
		dfs(sum*10,pos+1);
		dfs(sum*10+5,pos+1);
	}
	else if(pos%2==0)
	{
		for(int i=0;i<10;i+=2)
		{
			ll num=sum*10+i;
			if(num%pos==0)
			dfs(num,pos+1);
		}
	}
	else
	{
		if(pos==1)
		{
			for(int i=1;i<10;i++)
			{
				ll num=sum*10+i;
				if(num%pos==0)
				dfs(num,pos+1);
			}
		}
		else
		{
			for(int i=0;i<10;i++)
			{
				ll num=sum*10+i;
				if(num%pos==0)
				dfs(num,pos+1);
			}
		}
	}
}
int main ()
{
	cin>>n>>a>>b;
	dfs(0ll,1);
	if(!cnt) cout<<"No Solution";
	return 0;
}
