#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[93],t,a;
int main ()
{
	f[1]=1;
	f[2]=1;
	for(int i=3;i<=92;i++)
	f[i]=f[i-1]+f[i-2];
	cin>>t;
	while(t--)
	{
		cin>>a;
		int pos=lower_bound(f+1,f+93,a)-f;
		if(pos==1)
		cout<<1<<endl;
		else
		{
			if(abs(f[pos-1]-a)<=abs(f[pos]-a))
			cout<<pos-1<<endl;
			else
			cout<<pos<<endl;
		}
	}
	return 0;
}