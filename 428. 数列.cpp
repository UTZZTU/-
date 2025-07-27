#include <bits/stdc++.h>
using namespace std;
string u;
int k,n,ans,pos=1;
int main ()
{
	cin>>k>>n;
	while(n)
	{
		u+='0'+n%2;
		n/=2;
	}
	for(int i=0;i<u.size();i++)
	{
		ans+=(u[i]-'0')*pos;
		pos*=k;
	}
	cout<<ans;
	return 0;
}