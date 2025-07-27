#include <bits/stdc++.h>
using namespace std;
int t,a[10];
int c=6+180+300+120+120+1200+3600+3600,b=6*6*6*6*6;
bool judge1()
{
	if(a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4]&&a[4]==a[5]) return true;
	return false;
}
bool judge2()
{
	if(a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4]||a[2]==a[3]&&a[3]==a[4]&&a[4]==a[5]) return true;
	return false;
}
bool judge3()
{
	if(a[1]==a[2]&&a[3]==a[4]&&a[4]==a[5]||a[1]==a[2]&&a[2]==a[3]&&a[4]==a[5]) return true;
	return false;
}
bool judge4()
{
	if(a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5&&a[5]==6) return true;
	return false;
}
bool judge5()
{
	if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5) return true;
	return false;
}
bool judge6()
{
	if(a[1]==a[2]&&a[2]==a[3]||a[2]==a[3]&&a[3]==a[4]||a[3]==a[4]&&a[4]==a[5]) return true;
	return false;
}
bool judge7()
{
	int tt=0;
	for(int i=2;i<=5;i++)
	{
		if(a[i]==a[i-1]) tt++;
	}
	if(tt==2) return true;
	return false;
}
bool judge8()
{
	int tt=0;
	for(int i=2;i<=5;i++)
	{
		if(a[i]==a[i-1]) tt++;
	}
	if(tt==1) return true;
	return false;
}
int main ()
{
	cin>>t;
	while(t--)
	{
		for(int i=1;i<=5;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+1+5);
		if(judge1())
		{
			printf("0 0 1\n");
		}
		else if(judge2())
		{
			printf("1 1 6\n");
		}
		else if(judge3())
		{
			printf("2 11 36\n");
		}
		else if(judge4())
		{
			printf("0 0 0\n");
		}
		else if(judge5())
		{
			printf("0 0 0\n");
		}
		else if(judge6())
		{
			printf("1 1 3\n");
		}else if(judge7())
		{
			printf("1 1 3\n");
		}
		else if(judge8())
		{
			printf("1 1 2\n");
		}
		else
		{
			printf("5 %d %d",c/__gcd(c,b),b/__gcd(c,b));
		}
	}
	return 0;
}