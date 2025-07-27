#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7+5;
bool st[N];
int n,res;
signed main ()
{
	scanf("%lld",&n);
	st[1]=true;
	for(int i=1;i<=5000000;i++)
	{
		for(int j=i+1;;j++)
		{
			if(j*j<=10000000) st[j*j]=true;
			if(j*j-i*i<=10000000)
			{
				st[j*j-i*i]=true;
			}
			else break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(st[i]) res++;
	}
	cout<<res;
	return 0;
}