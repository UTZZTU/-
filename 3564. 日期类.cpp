#include <bits/stdc++.h>
using namespace std;
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main ()
{
	int t,year,month,day;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		scanf("%d %d %d",&year,&month,&day);
		day++;
		if(day>a[month])
		{
			day=1;
			month++;
		}
		if(month>12)
		{
			month=1;
			year++;
		}
		printf("%04d-%02d-%02d\n",year,month,day);
	}
	return 0;
}