#include <iostream>
using namespace std;
typedef long long ll;
ll minn=0x3f3f3f3f3f3f3f3f,n,a,b,res,ans;
string u;
ll num(string s)
{
	ll tt=0;
	for(int i=0;i<n/2;i++)
	{
		if(s[i]!=s[n-1-i])
		tt+=b;
	}
	return tt;
}
int main ()
{
	cin>>n>>a>>b;
	getchar();
	cin>>u;
	for(int i=1;i<=n;i++)
	{
		res=num(u);
		minn=min(minn,res+ans);
		u=u.substr(1,n-1)+u[0];
		ans+=a;
	}
	cout<<minn;
	return 0;
}