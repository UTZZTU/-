#include <stdio.h>
#include <string.h>
char s[15000][300];
int main ()
{
	int n,i,a[15005],max=0,j,min=300,js=0;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
    	scanf("%s",&s[i]);
    	a[i]=strlen(s[i]);
    	if(a[i]>max)
    	max=a[i];
    	if(a[i]<min)
    	min=a[i];
	}
	for(i=max;i>=min;i--)
	{
		for(j=0;j<n;j++)
		{
			if(a[j]==i)
			{
				printf("%s",s[j]);
				js++;
				if(js!=n)
			printf("\n");
			}
		}
	}
	return 0;
}
