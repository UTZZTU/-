#include <bits/stdc++.h>
using namespace std;
int t,l,r,x,a,b;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&l,&r,&x);
		scanf("%d%d",&a,&b);
		if(a==b) puts("0");
		else
		{
			if(a>b) swap(a,b);
			if(abs(b-a)>=x) puts("1");
			else if(r-a>=x&&r-b>=x||a-l>=x&&b-l>=x) puts("2");
			else if(r-a>=x&&r-l>=x&&b-l>=x) puts("3");
			else puts("-1");
		}
	}
	return 0;
}