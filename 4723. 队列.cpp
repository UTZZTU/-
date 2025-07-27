#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,f[55],rs;
char s[5]={'e','d','c','b','a'};
int main ()
{
	for(int i=1;i<=50;i++)
	f[i]=f[i-1]+(ll)pow(2,i-1)*5;
	cin>>n;
	int i=1;
	for(i;i<=50;i++)
	{
		if(f[i]>=n)
		break;
	}
	ll p=f[i]-n;
	p/=(ll)pow(2,i-1);
	cout<<s[p];
	return 0;
}