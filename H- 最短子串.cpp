#include <stdio.h>
#include <string.h>
int main ()
{
	char s[200010];
	int i,n,sum=9999999,j,a[3],pd=0,pd2=0;
	scanf("%s",s);
	for(i=0;s[i]!='\0';i++)
	{
		pd=0;
			memset(a,0,sizeof(a));
			a[s[i]-'1']++;
			for(j=i+1;s[j]!='\0';j++)
			{
				a[s[j]-'1']++;
				if(a[0]>=1&&a[1]>=1&&a[2]>=1)
				{
					pd=1;
					break;
				}
			}
			if(pd==0&&i==0&&s[j]=='\0')
			{
				printf("0");
				pd2=1;
				break;
			}
			else if(pd==1)
			{
				n=j-i+1;
				if(n<sum)
				sum=n;
			}
	}
	if(pd2==0)
	{
		printf("%d",sum);
	}
	return 0;
}
