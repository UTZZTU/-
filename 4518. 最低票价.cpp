#include <bits/stdc++.h>
using namespace std;
int days[400],costs[400],f[1010];
int n;
int get(int i,int cnt)
{
	int day=i;
	while(day>=1&&days[day]>=days[i]-cnt+1) day--;
	return day;
}
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	scanf("%d",&days[i]);
	for(int i=1;i<=3;i++)
	scanf("%d",&costs[i]);
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1]+costs[1];
		f[i]=min(f[i],f[get(i,7)]+costs[2]);
		f[i]=min(f[i],f[get(i,30)]+costs[3]);
	}
	cout<<f[n];
	return 0;
}