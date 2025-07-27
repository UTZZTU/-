#include <bits/stdc++.h>
using namespace std;
int n,lg[100010],res1,res2;
int main ()
{
	cin>>n;
	while(n>1)
	{
		res1++;
		res2+=n/2;
		if(n&1) n-=n/2;
		else n/=2;
	}
	cout<<res1<<" "<<res2;
	return 0;
}