#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
typedef long long ll;
int n,m,t;
bool fun(char s[])
{
	int ks=2,i,a1=0,a2=0;
	for(i=1;i<=t;i++)
	{
		if(s[i]=='1')
		{
			a1++;
			ks*=2;
		}
		else if(s[i]=='0')
		{
			a2++;
			if(ks==0)
			return false;
			ks--;
		}
	}
	if(ks==0&&a1==n&&a2==m)
	{
		return true;
	}
	else
	return false;
}
int main ()
{
	ll sum=0;
	int i,j;
	cin>>n>>m;
	char s[300];
	t=n+m;
	for(i=0;i<=t;i++)
	{
		s[i]='0';
	}
	s[i]='\0';
	for(i=1;;i++)
	{
		s[t]++;
		j=t;
		while(s[j]>='2')
		{
			s[j]='0';
			j--;
			s[j]++;
		}
		if(s[t]!='0')
		continue;
		if(s[0]>='1')
		break;
		if(fun(s))
		sum++;
		sum%=1000000007;
		
	}
	printf("%d",sum);
	return 0;
}
