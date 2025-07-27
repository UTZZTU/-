#include <stdio.h>
#include <string.h>
int main ()
{
	int n,i,t,x,c[115],j,a,m,g=0;
	char s[115][15],w[15],q,r;
	scanf("%d",&n);
	m=n;
	for(i=1;i<=n;i++)
	{
		getchar();
		t=0;
		for(a=0;a<15;a++)
		{
			scanf("%c",&q);
			if(q==' ')
			break;
			else 
			{
			   w[t]=q;
			   t++;
			}
		}
		w[t]='\0';
		scanf("%d",&x);
		strcpy(s[x],w);
		c[x]=i;
	}
	for(i=1;i<=n;i++)
	{
		r=i;
		for(j=i+1;j<=n;j++)
		{
			if(strcmp(s[r],s[j])==0)
			{
				strcpy(s[r],"0");
				c[r]=0;
				r=j;
			    m--;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(strcmp(s[i],"0")!=0)
		{
			printf("%d",c[i]);
			g++;
			if(g!=m)
			printf("\n");
		}
	}
	return 0;
}
