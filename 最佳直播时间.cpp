#include <bits/stdc++.h>
using namespace std;
int n,f[100010],ans,sum;
int main ()
{
	int h1,h2,m1,m2,s1,s2,sum1,sum2;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d:%d:%d - %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
		sum1=h1*60*60+m1*60+s1;
		sum2=h2*60*60+m2*60+s2;
		f[sum1]++;
		f[sum2+1]--;
	}
	for(int i=0;i<=90000;i++)
	{
		sum+=f[i];
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}