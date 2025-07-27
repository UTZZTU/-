#include <bits/stdc++.h>
using namespace std;
bool pd(int n)
{
	if(n%4==0&&n%100!=0||n%400==0)
	return true;
	else
	return false;
}
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main ()
{
	int y,m,d;
	while(scanf("%d-%d-%d",&y,&m,&d)!=EOF)
	{
		int ans=0;
		if(pd(y))
		a[2]=29;
		else
		a[2]=28;
		for(int i=1;i<m;i++)
		{
			ans+=a[i];
		}
		ans+=d;
		cout<<ans<<endl;
	}
	return 0;
}