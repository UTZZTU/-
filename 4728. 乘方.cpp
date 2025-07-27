#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,res=1;
int main ()
{
	cin>>a>>b;
	if(a==1)
	{
		cout<<1;
	}
	else
	{
		for(int i=1;i<=b;i++)
		{
			res*=a;
			if(res>1000000000)
			{
				cout<<-1;
				return 0;
			}
		}
		cout<<res;
	}
	return 0;
}