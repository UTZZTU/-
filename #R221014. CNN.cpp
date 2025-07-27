#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,bw,sum;
int main ()
{
	scanf("%lld",&n);
	while(n)
	{
		int t=n%10;
		t-=bw;
		if(9-t>=1&&n>=10)
		{
			t=9;
			bw=1;
		}
		else
		bw=0;
		sum+=t;
		n/=10;
	}
	cout<<sum;
	return 0;
}