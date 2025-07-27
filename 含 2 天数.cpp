#include <iostream>
using namespace std;
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool pd1(int n)
{
	if(n%4==0&&n%100!=0||n%400==0)
	return true;
	else
	return false;
}
bool pd2(int n)
{
	while(n!=0)
	{
		if(n%10==2)
		return true;
		n/=10;
	}
	return false;
}
int main ()
{
	int ans=0,rq,yf;
	for(int i=1900;i<=9999;i++)
	{
		if(pd2(i))
		{
			if(pd1(i))
			ans+=366;
			else
			ans+=365;
			continue;
		}
		if(pd1(i))
		a[2]=29;
		else
		a[2]=28;
		yf=1;
		rq=1;
		for(yf;yf<=12;yf++)
		{
			if(yf==2||yf==12)
			{
				ans+=a[yf];
				continue;
			}
		    rq=1;
		    for(rq;rq<=a[yf];rq++)
		    {
		    	if(pd2(rq))
		    	ans++;
			}
			
		}
	}
	cout<<ans;
	return 0;
}