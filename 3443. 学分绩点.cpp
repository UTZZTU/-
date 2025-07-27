#include <bits/stdc++.h>
using namespace std;
int n,f[20],res,num;
double ans;
double jd(int x)
{
	if(x>=90) return 4.0;
	if(x>=85) return 3.7;
	if(x>=82) return 3.3;
	if(x>=78) return 3.0;
	if(x>=75) return 2.7;
	if(x>=72) return 2.3;
	if(x>=68) return 2.0;
	if(x>=64) return 1.5;
	if(x>=60) return 1.0;
	return 0.0;
}
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		res+=f[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>num;
		ans+=jd(num)*f[i];
	}
	printf("%.2f",ans/res);
	return 0;
}