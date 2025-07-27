#include <bits/stdc++.h>
using namespace std;
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int b[7],n,xq;
bool judge(int n)
{
	if(n%4==0&&n%100!=0||n%400==0)
	return true;
	return false;
}
int main ()
{
	cin>>n;
	for(int i=1900;i<1900+n;i++)
	{
		if(judge(i))
		a[2]=29;
		else
		a[2]=28;
		for(int i=1;i<=12;i++)
		{
			xq+=13;
			xq%=7;
			b[xq]++;
			xq+=a[i]-13;
		}
	}
	cout<<b[6]<<" "<<b[0];
	for(int i=1;i<=5;i++)
	cout<<" "<<b[i];
	return 0;
}