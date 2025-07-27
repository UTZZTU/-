#include <iostream>
#include <string.h>
using namespace std;
int a[13];
bool fun(char s[])
{
	int i,mx=1,js,l,j,k;
	l=strlen(s);
	for(i=3;i<=5;i++)
	{
		js=1;
		k=i;
		for(j=i+1;j<l;j++,k++)
		{
			if(s[j]-s[k]==1)
			js++;
			else
			break;
			
		}
		if(js>mx)
		mx=js;
	}
	if(mx>=3)
	{
		printf("%s\n",s);
		return true;
	}
	else
	return false;
}
int main ()
{
	a[1]=31;
	a[2]=28;
	a[3]=31;
	a[4]=30;
	a[5]=31;
	a[6]=30;
	a[7]=31;
	a[8]=31;
	a[9]=30;
	a[10]=31;
	a[11]=30;
	a[12]=31;
	int i,j,k,m,n,sum=0;
	char s[10];
	for(i=1;i<=12;i++)
	{
		for(j=1;j<=a[i];j++)
		{
			m=i;
			n=j;
			s[0]='2';
			s[1]='0';
			s[2]='2';
			s[3]='2';
			s[5]=m%10+'0';
			m/=10;
			s[4]=m+'0';
			s[7]=n%10+'0';
			n/=10;
			s[6]=n+'0';
			s[8]='\0';
			if(fun(s))
			{
				sum++;
			}
		}
	}
	printf("%d",sum);
	//28
	//14
	return 0;
}
