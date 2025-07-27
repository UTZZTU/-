#include <bits/stdc++.h>
using namespace std;
int n,k,res;
int main ()
{
	cin>>n>>k;
	for(int i=10;i<=n*10;i*=10)
	{
		res+=n/i*(i/10);
		if((n%i)/(i/10)>=k)
		{
			res+=min(i/10,(n%i)-k*(i/10)+1);
		}
	}
	cout<<res;
	return 0;
}