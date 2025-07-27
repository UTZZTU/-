#include <stdio.h>
int main ()
{
	int i,a[14],n,m,max=0,sum=0;
	char s[10000];
	for(i=1;i<=13;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>max)
		max=a[i];
	}
	scanf("%d%d",&n,&m);
	getchar();
	scanf("%s",s);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]>='2'&&s[i]<='9')
			sum+=a[s[i]-'0'];
		else if(s[i]=='1')
		{
			i++;
			sum+=a[10];
		}
		else if(s[i]=='A')
			sum+=a[1];
		else if(s[i]=='J')
		sum+=a[11];
		else if(s[i]=='Q')
		sum+=a[12];
		else if(s[i]=='K')
		sum+=a[13];
	}
	sum+=m*max;
	printf("%d",sum);
	return 0;
}
