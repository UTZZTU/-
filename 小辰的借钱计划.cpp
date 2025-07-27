#include <bits/stdc++.h>
using namespace std;
int t,m,a;
int cnt;
double x;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		x=0;
		scanf("%d%d",&m,&a);
		for(int i=1;i+a<=m;i++)
		{
			if(a%i==0||i%a==0)
			{
				x+=i;
				cnt++;
			}
		}
		x=x*1.0/cnt;
		if(x>=a) puts("YES");
		else puts("NO");
	}
	return 0;
}