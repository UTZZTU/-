#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,k;
string u;
int main ()
{
	while(cin>>u)
	{
		if(u.size()==1&&u[0]=='0')
		break;
		k=2,ans=0;
		for(int i=u.size()-1;i>=0;i--)
		{
			ans+=(u[i]-'0')*(k-1);
			k*=2;
		}
		cout<<ans<<endl;
	}
	return 0;
}