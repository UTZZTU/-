#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,c[100010],a[100010],b[100010];
bool judge()
{
	for(int i=1;i<=n-i+1;i++)
	{
		if((c[i]-c[n+1-i])&1)
		{
			if(m&1)
			{
				b[i]=((c[i]-c[n+1-i])+m)/2%m;
				a[i]=(c[i]-b[i])%m;
				if((c[n+1-i]-(a[i]-b[i]))%m)
				return false;
				a[n+1-i]=a[i];
				b[n+1-i]=-b[i];
			}
			else
			{
				return false;
			}
		}
		else
		{
				b[i]=((c[i]-c[n+1-i])+2*m)/2%m;
				a[i]=(c[i]-b[i])%m;
				if((c[n+1-i]-(a[i]-b[i]))%m)
				return false;
				a[n+1-i]=a[i];
				b[n+1-i]=-b[i];
		}
	}
	return true;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>c[i];
	if(judge())
	{
		cout<<"Yes"<<endl;
		for(int i=1;i<=n;i++)
		cout<<((a[i]%m)+m)%m<<" ";
		cout<<endl;
		for(int i=1;i<=n;i++)
		cout<<((b[i]%m)+m)%m<<" ";
		cout<<endl;
	}
	else
	cout<<"No"<<endl;
	return 0;
}