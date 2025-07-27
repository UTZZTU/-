#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,f[500010],res;
string u;
int main ()
{
	cin>>n;
	getchar();
	cin>>u;
	for(int i=0;i<n;i++)
	{
		ll lhs=0;
		if(i>0&&u[i]!=u[i-1])
		{
			lhs++;
			for(int j=i-2;j>=0&&u[j]!=u[i];j--) lhs++;
		}
		ll rhs=0;
		if(i+1<n&&u[i]!=u[i+1])
		{
			rhs++;
			for(int j=i+2;j<n&&u[j]!=u[i];j++) rhs++;
		}
		res+=lhs*rhs+max((ll)0,lhs-1)+max((ll)0,rhs-1);
	}
	cout<<res;
	return 0;
}