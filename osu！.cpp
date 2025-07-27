#include <stdio.h>
int main ()
{
	char s[100];
	int n,sum,i,j,k,cs,w=0;
	scanf("%d",&n);
	getchar();
    for(i=0;i<n;i++)
    {
    	scanf("%c",&s[i]);
	}
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='o')
		{
			for(j=i+1;s[j]!='\0';j++)
			{
				if(s[j]=='s')
				{
						cs=0;
						for(k=j+1;s[k]!='\0';k++)
						{
							if(s[k]=='u')
							{
								cs++;
							}
						}
						w+=cs;
				}
			}
		}
	}
	printf("%d",w);
	return 0;
}
