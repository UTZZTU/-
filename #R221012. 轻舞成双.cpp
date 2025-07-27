#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum,n,m;
int main ()
{
	cin>>n>>m;
	if(n>=2)
	sum+=(n-1)*n/2;
	if(m>=2)
	sum+=(m-1)*m/2;
	cout<<sum;
	return 0;
}