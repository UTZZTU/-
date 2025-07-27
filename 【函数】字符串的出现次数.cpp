#include <stdio.h>
#include <string.h>
int main ()
{
	int t,i,len,j,a,sum,q,s;
	char str[200],substr[200];
	scanf("%d",&t);
	getchar();
	for(i=1;i<=t;i++)
	{
		s=0;
		gets(str);
		gets(substr);
		len=strlen(substr);
		for(j=0;str[j]!='\0';j++)
		{
			if(str[j]==substr[0])
			{
				sum=1;
				q=1;
				j++;
				while(str[j]==substr[q]&&substr[q]!='\0')
				{
					sum++;
					q++;
					j++;
				}
				if(sum==len)
				{
					s++;
					j--;
				}
				else
				{
					j-=sum;
				}
			}
		}
		printf("%d",s);
		if(i!=t)
		printf("\n");
	}
	return 0;
}
