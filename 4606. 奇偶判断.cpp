#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,k=1;
string u;
int main ()
{
	cin>>u;
	for(int i=u.size()-1;i>=0;i--)
	{
		if(u[i]>='0'&&u[i]<='9')
		ans+=k*(u[i]-'0');
		else
		ans+=k*(u[i]-'A'+10);
		k*=16;
	}
	if(ans&1)
	cout<<1;
	else
	cout<<0;
	return 0;
}