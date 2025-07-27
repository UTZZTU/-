#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,minn=1e18;
bool check(ll x)
{
	int pos1=0,pos2=0;
	while(x)
	{
		if(x%10==4)
		pos1++;
		else
		pos2++;
		x/=10;
	}
	return pos1==pos2;
}
void dfs(ll x)
{
	if(x>=n)
	{
		if(check(x))
		{
			minn=min(minn,x);
			return;
		}
	}
	if(x>minn)
	return;
	dfs(x*10+4);
	dfs(x*10+7);
}
int main ()
{
	cin>>n;
	dfs(0);
	cout<<minn;
	return 0;
}