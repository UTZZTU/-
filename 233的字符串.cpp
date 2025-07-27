#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
ll f[3],n,res=1;
int main ()
{
	cin>>n;
	n--;
	f[0]=n;
	f[1]=n+1;
	f[2]=n+2;
	for(int i=0;i<3;i++)
	{
		if(f[i]%2==0)
		{
			f[i]/=2;
			break;
		}
	}
	for(int i=0;i<3;i++)
	{
		if(f[i]%3==0)
		{
			f[i]/=3;
			break;
		}
	}
	for(int i=0;i<3;i++)
	{
		res=res*f[i]%MOD;
	}
	cout<<res;
	return 0;
}