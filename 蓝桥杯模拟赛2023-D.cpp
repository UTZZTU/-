#include <bits/stdc++.h>
using namespace std;
int n,f[100],res;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(f[i]*f[j]>=2022)
			{
				res++;
			}
		}
	}
	cout<<res;
	return 0;
}
//蓝桥杯模拟赛2023-D