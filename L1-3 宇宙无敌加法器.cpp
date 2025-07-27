#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
	char s1[30],s2[30],s3[30];
	int s[30],i;
	memset(s,0,sizeof(s));
	int l1,l2,l3,l,jw=0,num,q1,q2,u,jz;
	scanf("%s",s1);
	scanf("%s",s2);
	scanf("%s",s3);
	l1=strlen(s1);
	l2=strlen(s2);
	l3=strlen(s3);
	l=max(l2,l3);
	u=l;
	l2--;
	l3--;
	l1--;
	for(l;l>=0;l--)
	{
		if(l2<0)
		q1=0;
		else
		q1=s2[l2]-'0';
		if(l3<0)
		q2=0;
		else
		q2=s3[l3]-'0';
		num=q1+q2+jw;
		jz=s1[l1]-'0';
		if(jz==0)
		jz=10;
		s[l]=num%jz;
		jw=num/jz;
		l2--;
		l3--;
		l1--;
	}
	for(i=0;s[i]==0&&i<u;i++)
	;
	for(i;i<=u;i++)
	printf("%d",s[i]);
	return 0;
}