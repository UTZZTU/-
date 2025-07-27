#include <bits/stdc++.h>
using namespace std;
int t;
char u[1000010];
int main ()
{
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		scanf("%s",u);
		int flag=0,a=0,b=0;
		for(int i=0;u[i]!='\0';i++)
		{
			if(u[i]=='(')
			{
				a++;
			}
			else
			{
				if(a) a--;
			}
		}
		if(a==0) printf("%s\n",u);
		else printf("impossible\n");
	}
	return 0;
}