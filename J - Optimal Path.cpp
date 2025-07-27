#include <bits/stdc++.h>
using namespace std;
int t,n,m;
long long sum;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		sum=(long long)m*(1+m)/2;
		sum+=(long long)n*(m+(long long)m*n)/2;
		sum-=m;
		cout<<sum<<endl;
	}
	return 0;
}
