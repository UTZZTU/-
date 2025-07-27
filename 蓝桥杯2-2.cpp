#include <bits/stdc++.h>
using namespace std;
int a[13]={0,31,30,31,30,31,30,31,31,30,31,30,31};
bool judge(int x)
{
	if(x%4==0&&x%100!=0||x%400==0)
	return true;
	else
	return false;
}
int main ()
{
	int year=1949,month=10,day=0;
	for(year;year<2022;year++)
	{
		if(judge(year))
		a[2]=29;
		else
		a[2]=28;
		for(month;month<=12;month++)
		day+=a[month];
		month=1;
	}
	cout<<day;
	return 0;
}