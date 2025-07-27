#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main ()
{
	int n,m,a[120][120],b[120],i,j,q,w,e,pd1=0,pd2=0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	char s[200][20],name1[20],name2[20];
	scanf("%d%d",&n,&m);
	getchar();
	j=0;
	for(i=1;i<=m;i++)
	{
		scanf("%s %s",name1,name2);
		if(j==0)
		{
			strcpy(s[j],name1);
			j++;
			strcpy(s[j],name2);
			j++;
			a[0][1]=a[1][0]=1;
			b[0]++;
			b[1]++;
		}
		else
		{
			pd1=0;
			pd2=0;
			for(e=0;e<j;e++)
			{
				if(strcmp(name1,s[e])==0)
				{
					pd1=1;
					q=e;
				}
				if(strcmp(name2,s[e])==0)
				{
					pd2=1;
					w=e;
				}
			}
			if(pd1==0)
			{
				q=j;
				strcpy(s[q],name1);
				j++;	
			}
			if(pd2==0)
			{
				w=j;
				strcpy(s[w],name2);
				j++;
			}
			if(a[q][w]!=1&&a[w][q]!=1)
			{
				a[q][w]=a[w][q]=1;
				b[q]++;
				b[w]++;
			}
		}
	}
	sort(b,b+j);
	printf("%d",b[j-1]);
	return 0;
}
