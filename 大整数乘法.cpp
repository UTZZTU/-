#include <stdio.h>
#include <string.h>
int main ()
{
	char s1[205],s2[205];
	int l1,l2,i,j,jw=0,shu,s[410],jf[205],zws=409,fws,q;
	gets(s1);
	gets(s2);
	l1=strlen(s1);
	l2=strlen(s2);
	memset(jf,0,sizeof(jf));
	memset(s,0,sizeof(s));
	for(i=l2-1;i>=0;i--)
	{
		jw=0;
		fws=l1;
		for(j=l1-1;j>=0;j--)
		{
			shu=(s2[i]-'0')*(s1[j]-'0')+jw;
			jw=shu/10;
			shu%=10;
			jf[fws]=shu;
			fws--;
			if(fws==0)
			{
				jf[fws]=jw;
			}
		}
		jw=0;
		q=zws;
		for(j=l1;j>=0;j--)
		{
			shu=s[q]+jf[j]+jw;
			jw=shu/10;
			shu%=10;
			s[q]=shu;
			q--;
			if(j==0)
			s[q]+=jw;
		}
		zws--;
	}
	for(i=0;i<=408&&s[i]==0;i++)
	;
	for(;i<=409;i++)
	{
		printf("%d",s[i]);
	}
	return 0;
}
