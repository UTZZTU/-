#include <bits/stdc++.h>
using namespace std;
int t,n,m;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		if(min(n,m)<2||max(n,m)<3) puts("No");
		else
		{
			if((n%2==0)&&(m%3==0)||(n%3==0)&&(m%2==0)) puts("Yes");
			else if((n%2==0)&&(n%3==0)||(m%2==0)&&(m%3==0)) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}