#include <bits/stdc++.h>
using namespace std;
int t,n;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n<3) puts("NO");
		else if(n%3==0)
		{
			if(n<=9) puts("NO");
			else
			{
				puts("YES");
				printf("%d %d %d\n",1,4,n-5);
			}
		}
		else if(n%3==1)
		{
			if(n<=4) puts("NO");
			else
			{
				puts("YES");
				printf("%d %d %d\n",1,2,n-3);
			}
		}
		else if(n%3==2)
		{
			if(n<=5) puts("NO");
			else
			{
				puts("YES");
				printf("%d %d %d\n",1,2,n-3);
			}
		}
	}
	return 0;
}