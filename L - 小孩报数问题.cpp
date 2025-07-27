#include <stdio.h>
#include <string.h>
const int N = 64;
const int N2 = 15;
char name[N][N2 + 1];
int main ()
{
	int n,w,s,a;
	scanf("%d",&n);
	getchar();
	for(a=0;a<n;a++)
	{
		scanf("%s",name[a]);
	}
	scanf("%d,%d",&w,&s);
	int i=w-2,pm=0,cn=0;
			while(cn<n)
			{
				i=i+1;
				if(i==n)
				i=0;
				if(name[i][0]!='0')
				{
					pm++;
					if(pm==s)
					{
					    printf("%s\n",name[i]);
						name[i][0]='0';
						cn++;
						pm=0;
						
					}
				}
			}
			return 0;
}
