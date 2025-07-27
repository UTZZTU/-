#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
ll f[1010],num[1010],n,res=1,x;
int main ()
{
	cin>>n;
	int i=1,j=n;
	while(res<=n)
	{
		if(i<=j)
		{
			f[i]=res;
			res++;
			i++;
		}
		else
		break;
		if(i<=j)
		{
			f[j]=res;
			res++;
			j--;
		}
		else
		break;
		if(i<=j)
		{
			f[j]=res;
			res++;
			j--;
		}
		else
		break;
		if(i<=j)
		{
			f[i]=res;
			res++;
			i++;
		}
		else
		break;
	}
	for(int i=1;i<=n;i++)
	{
		num[i]=f[i];
	}
	x=n-1;
	while(x--)
	{
		for(int i=1;i<=x+1;i++)
		{
			num[i]=(num[i]+num[i+1])%MOD;
		}
	}
	cout<<num[1]%MOD<<endl;
	for(int i=1;i<=n;i++)
	cout<<f[i]<<" ";
	return 0;
}