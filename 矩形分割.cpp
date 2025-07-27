#include <bits/stdc++.h>
using namespace std;
int n,m;
int solve(int x,int y)
{
	int res=0;
	while(1)
	{
		if(x==0||y==0) break;
		res+=y/x*x;
		int t=y%x;
		y=x;
		x=t;
	}
	return res;
}
int main ()
{
	scanf("%d%d",&n,&m);
	if(n==m)
	{
		printf("%d",n);
	}
	else
	{
		if(n>m) swap(n,m);
		cout<<solve(n,m);
	}
	return 0;
}