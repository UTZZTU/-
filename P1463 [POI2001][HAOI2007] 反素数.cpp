#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[9]={2,3,5,7,11,13,17,19,23},sum,maxx;
void dfs(ll level,ll xz,ll num,ll ys)
{
	if(ys>sum||ys==sum&&num<maxx)
	{
		maxx=num;
		sum=ys;
	}
	if(level==9) return;
	for(int i=1;i<=xz;i++)
	{
		if(num*a[level]>n) break;
		num*=a[level];
		dfs(level+1,i,num,ys*(i+1));
	}
}
int main ()
{
	cin>>n;
	dfs(0,30,1,1);
	cout<<maxx;
	return 0;
}