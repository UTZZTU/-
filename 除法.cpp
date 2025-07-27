#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
char ans[]="0123456789";
int main ()
{
	int n,i,m,flag;
    char s[20];
	while(scanf("%d",&n)!=EOF)
	{
		flag=0;
		if(n==0)
		break;
		else
		{
			for(i=1234;i<50000;i++)
			{
				m=i*n;
				if(m>98765)
				break;
				sprintf(s,"%05d%05d",i,m);
				sort(s,s+10);
				if(strcmp(ans,s)==0)
				{
					printf("%05d / %05d = %d\n",m,i,n);
					flag=1;
				}
			}
			if(flag==0)
			printf("There are no solutions for %d.\n",n);
		}
	}
	return 0;
}
