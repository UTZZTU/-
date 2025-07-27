#include <bits/stdc++.h>
using namespace std;
int y[1010],n,k;
int main ()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
	scanf("%d %d",&k,&y[i]);
	sort(y+1,y+1+n);
	int Y,sum=0;
	if(n&1)
	Y=y[n/2+1];
	else
	Y=(y[n/2]+y[n/2+1])/2;
	for(int i=1;i<=n;i++)
	{
		sum+=abs(y[i]-Y);
	}
	cout<<sum<<endl;
	}
	return 0;
}
