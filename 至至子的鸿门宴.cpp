#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,n,a;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		ans+=a-i;
	}
	if(ans&1)
	cout<<"ZZZ";
	else
	cout<<"SSZ";
	return 0;
}