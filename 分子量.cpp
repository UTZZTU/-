#include <stdio.h>
#include <string.h>
int main ()
{
	char s[100];
	int c[100],i,w[100],sum,r,q,j,t,u;
	while(gets(s)!=NULL)
	{
		memset(c,0,sizeof(c));
		for(i=0;s[i]!='\0';i++)
		{
			if(s[i]>='A'&&s[i]<='Z')
			{
				c[s[i]-'A']++;
			}
			else if(s[i]>='0'&&s[i]<='9')
			{
				q=i;
				sum=1;
				r=1;
				w[0]=s[i]-'0';
				t=1;
				u=0;
				while(s[i+1]>='0'&&s[i+1]<='9')
				{
					sum++;
					i++;
					w[r]=s[i]-'0';
					r++;
				}
				for(j=sum-1;j>=0;j--)
				{
					u+=w[j]*t;
					t*=10;
				}
				c[s[q-1]-'A']+=u-1;
			}
		}
		printf("%.3fg/mol\n",c['C'-'A']*12.01+c['H'-'A']*1.008+c['O'-'A']*16.00+c['N'-'A']*14.01);
	}
	return 0;
}
