#include <bits/stdc++.h>
using namespace std;
int a[13]={0,31,31,31,30,31,30,31,31,30,31,30,31},n=2022,xq=5,sum;
void judge(int x)
{
	if(x%4==0&&x%100!=0||x%400==0)
	a[2]=29;
	else
	a[2]=28;
}
int main ()
{
	judge(n);
	for(int i=1;i<=12;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			xq++;
			xq%=7;
			if(xq==6||xq==0||j==1||j==11||j==21||j==31)
			sum++;
		}
	}
	cout<<sum;
	return 0;
}