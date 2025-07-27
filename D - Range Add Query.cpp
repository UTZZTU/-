#include <iostream>
using namespace std;
typedef long long ll;
ll n,k,a[200010],cf[200010],f[200010],l,r,q;
bool judge(int l,int r)
{
	
	for(int i=r+1-k+2;i<=r;i++)
	{
		cout<<i<<endl;
		if(cf[i]==0||i+k<=r&&cf[i]+cf[i+k]==0||i-k>=l&&cf[i]+cf[i-k]==0)
		;
		else
		return false;
	}
	return true;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cf[i]=a[i]-a[i-1];
		f[i]=f[i-1]+cf[i];
	}
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		if(judge(l,r))
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
	return 0;
}