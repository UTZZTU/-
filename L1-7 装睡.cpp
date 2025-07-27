#include<stdio.h>
int main ()
{
	int n,i,q,h;
	char s[5];
	scanf("%d",&n);
	getchar();
	for(i=1;i<=n;i++)
	{
		scanf("%s %d %d",s,&q,&h);
		if(q<15||q>20||h<50||h>70)
		printf("%s\n",s);
	}
	return 0;
}