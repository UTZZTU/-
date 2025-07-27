#include <bits/stdc++.h>
using namespace std;
int a[13]={0,31,29,31,30,31,30,31,31,30,31,30,31},year,mon,day,ans;
int main ()
{
	while(scanf("%d/%d/%d",&year,&mon,&day)!=EOF)
	{
		ans=0;
		if(year%4==0&&year%100!=0||year%400==0)
		a[2]=29;
		else
		a[2]=28;
		for(int i=1;i<mon;i++)
		ans+=a[i];
		ans+=day;
		cout<<ans<<endl;
	}
	return 0;
}