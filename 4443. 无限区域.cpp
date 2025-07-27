#include <bits/stdc++.h>
using namespace std;
const double PI = 3.141592654037;
int t,a,b,r;
double s;
int main ()
{
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d%d",&r,&a,&b);
		s=0;
		s+=PI*r*r;
		while(r)
		{
			r=r*a;
			s+=PI*r*r;
			r=r/b;
			s+=PI*r*r;
		}
		printf("Case #%d: %.6f\n",i,s);
	}
	return 0;
}