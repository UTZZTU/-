#include <bits/stdc++.h>
using namespace std;
int a,b,n,money=0x3f3f3f3f,pd1,pd2;
int main ()
{
	cin>>a>>b>>n;
	for(int i=1,cost,k,p;i<=n;i++)
	{
		cin>>cost>>k;
		pd1=0,pd2=0;
		for(int j=1;j<=k;j++)
		{
			cin>>p;
			if(p==a)
			pd1++;
			if(p==b&&pd1)
			pd2++;
		}
		if(pd1&&pd2)
		money=min(money,cost);
	}
	if(money==0x3f3f3f3f)
	money=-1;
	cout<<money;
	return 0;
}