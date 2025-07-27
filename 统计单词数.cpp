#include <stdio.h>
#include <string.h>
int main ()
{
	char s1[15],s[1000010],q;
	int i=0,pd=0,wz=-1,l1,k,j,zd=0,cs=0;
	scanf("%s",s1);
	getchar();
	l1=strlen(s1);
	while(scanf("%c",&q)!=EOF)
	{
		if(q=='\n')
		break;
		else
		{
			s[i]=q;
		i++;
		}
	}
	s[i]='\0';
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]==s1[0]||s[i]-s1[0]==32||s1[0]-s[i]==32)
		{
			k=i;
			for(j=0;(s[k]==s1[j]||s[k]-s1[j]==32||s1[j]-s[k]==32)&&j<l1;k++,j++)
			;
			if(j==l1)
			{
				if((s[k]==' '||s[k]=='\0')&&(s[k-j-1]==' '||k-j-1<0))
				{
					cs++;
				zd=1;
				if(zd==1&&pd==0)
				{
					wz++;
					pd=1;
				}
				}
				else
				{
					i+=j;
					i-=1;
					if(pd==0)
					wz+=j;
				}
			}
			else
			{
				i+=j;
				i-=1;
				if(pd==0)
				wz+=j;
			}
		}
		else
		{
			if(pd==0)
			wz++;
		}
	}
	if(pd==0)
	printf("-1");
	else
	printf("%d %d",cs,wz);
	return 0;
}