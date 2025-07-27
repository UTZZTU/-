#include <bits/stdc++.h>
using namespace std;
char s[110];
bool judge(char s[])
{
	int q=0,z=0,h=0,sump=0,sumt=0,wz1=-1,wz2=strlen(s);
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i]!='P'&&s[i]!='T'&&s[i]!='A')
		return false;
		if(s[i]=='P')
		sump++;
		if(s[i]=='T')
		sumt++;
	}
	if(sump>1||sumt>1)
	return false;
	for(int i=0;s[i]=='A';i++)
	{
		q++;
		wz1=i;
	}
	for(int i=strlen(s)-1;s[i]=='A';i--)
	{
		h++;
		wz2=i;
	}
	if(s[wz1+1]!='P'||s[wz2-1]!='T')
	return false;
	for(int i=wz1+1;i<=wz2-1;i++)
	{
		if(s[i]=='A')
		z++;
	}
	while(z>2)
	{
		if(h<q)
		return false;
		h-=q;
		z-=1;
	}
	if(z==1&&q==h)
	return true;
	if(z==2&&(h==2*q||h==0&&q==0))
	return true;
	return false;
}
int main ()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		if(judge(s))
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}