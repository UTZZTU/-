#include <bits/stdc++.h>
using namespace std;
int t;
double a,b,c,perm;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf",&a,&b,&c);
		perm=(a+b)/2.0;
		perm=ceil((double)fabs(a-perm)/c);
		printf("%d\n",(int)perm);
	}
	return 0;
}