#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,p,res=1,pos=1;
int main ()
{
	cin>>n>>p;
	for(int i=1;i<=n;i++)
	{
		pos=pos*2%p;
		if(pos<0) cout<<pos<<endl;
	}
	cout<<pos<<endl;
	for(int i=1;i<=pos;i++)
	{
		res=res*2%p;
	}
	cout<<res;
	return 0;
}