#include <bits/stdc++.h>
using namespace std;
int t,ans,x;
string u;
int main ()
{
	cin>>t;
	getchar();
	while(t--)
	{
		ans=0;
		x=0;
		getline(cin,u);
		for(int i=0;i<u.size();i++)
		{
			if(u[i]>='0'&&u[i]<='9')
			x=x*10+u[i]-'0';
			else
			{
				ans+=x;
				x=0;
			}
		}
		ans+=x;
		cout<<ans<<endl;
	}
	return 0;
}