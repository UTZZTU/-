#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll sum,maxx=0x3f3f3f3f3f3f3f3f;
ll a[9]={2,3,5,7,11,13,17,19,23};
ll b[9];
void dfs(ll cs,ll xz,ll num,ll ys)
{
	if(ys>sum||ys==sum&&num<maxx)
	{
		sum=ys;
		maxx=num;
	}
	if(cs==9) return;
	for(int i=1;i<=xz;i++)
	{
		if(num*a[cs]>n) break;
		num*=a[cs];
		dfs(cs+1,i,num,ys*(i+1));
	}
}
int main ()
{
	cin>>n;
	dfs(0,30,1,1);
	cout<<maxx;
	return 0;
}