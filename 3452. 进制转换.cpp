#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,js;
string u;
int main ()
{
	while(cin>>u)
	{
		ans=0;
		js=1;
		for(int i=u.size()-1;i>=0;i--)
		{
			if(u[i]=='x')
			{
				if(u[0]=='-')
				ans*=-1;
				cout<<ans<<endl;
				break;
			}
			else if(u[i]>='a'&&u[i]<='z')
			{
				ans+=(u[i]-'a'+10)*js;
			}
			else if(u[i]>='0'&&u[i]<='9')
			{
				ans+=(u[i]-'0')*js;
			}
			js*=16;
		}
	}
	return 0;
}