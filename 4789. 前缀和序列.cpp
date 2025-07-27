#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100010],b[100010],n,m,l,r,q;
int main ()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++)
	{
		a[i]+=a[i-1];
		b[i]+=b[i-1];
	}
	cin>>m;
	while(m--)
	{
		cin>>q>>l>>r;
		if(q==1)
		printf("%lld\n",a[r]-a[l-1]);
		else
		printf("%lld\n",b[r]-b[l-1]);
	}
	return 0;
}