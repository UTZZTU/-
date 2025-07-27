#include <stdio.h>
char s[1010];
int ans=1;
void fun(int n)
{
	int i,pd=0,j,k=0;
	
	while(pd==0)
	{
        i=k;
		j=n;
		for(i;i<j&&s[i]==s[j];i++,j--);
		if(i>=j)
		{
			if(n-k+1>ans)
			ans=n-k+1;
			pd=1;
		}
		else
		k++;
	}
}
int main ()
{
	int j;
	gets(s);
	for(j=1;s[j]!='\0';j++)
	{
		fun(j);
	}
	printf("%d",ans);
	return 0;
}