#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll res,f[3000];
ll num(ll x)
{
	int cnt=0;
	while(x>=10)
	{
		ll t=0;
		while(x)
		{
			t+=x%10;
			x/=10;
		}
		x=t;
		cnt++;
	}
	return cnt+1;
}
int main ()
{
//	for(ll i=1;i<=2022;i++)
//	{
//		f[i]=num(i);
//	}
//	for(int i=1;i<=2022;i++)
//	{
//		for(int j=i+1;j<=2022;j++)
//		{
//			for(int k=j+1;k<=2022;k++)
//			{
//				if(f[k]>f[j]&&f[j]>f[i]) res++;
//			}
//		}
//	}
	cout<<"24053742";
	return 0;
}