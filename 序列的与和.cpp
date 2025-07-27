#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[100],res;
bool check(ll num){
	int pos=0;
	while(num)
	{
		if(num&1) pos++;
		num>>=1;
	}
	return pos==k;
}
void dfs(int level,ll num,ll ge)
{
	if(level>n)
	{
		if(ge>0&&check(num)) res++;
		return;
	}
	dfs(level+1,num,ge);
	if(ge==0)
	{
		dfs(level+1,a[level],ge+1);
	}
	else
	{
		dfs(level+1,num&a[level],ge+1);
	}
	
}
int main ()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,(ll)0,(ll)0);
	cout<<res;
	return 0;
}