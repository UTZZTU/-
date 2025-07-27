#include <bits/stdc++.h>
using namespace std;
int l[100010],n,m,ans;
double le,ri,mi;
bool check(double x)
{
	ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=floor(l[i]*1.0/x);
		if(ans>=m)
		return true;
	}
	return false;
}
int main ()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&l[i]);
	le=0.0,ri=1e9;
	ri*=1.0;
	while(ri-le>1e-3)
	{
		mi=(ri+le)*1.0/2;
		if(check(mi))
		le=mi;
		else
		ri=mi;
	}
	printf("%.2f",le);
	return 0;
}