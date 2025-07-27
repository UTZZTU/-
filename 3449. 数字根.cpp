#include <bits/stdc++.h>
using namespace std;
int ans,n;
string u;
int main ()
{
	while(cin>>u)
	{
		if(u[0]=='0'&&u.size()==1||u[0]=='-')
		break;
		n=0;
		for(int i=0;i<u.size();i++)
		n+=u[i]-'0';
		while(n>=10)
		{
			ans=0;
			while(n)
			{
				ans+=n%10;
				n/=10;
			}
			n=ans;
		}
		cout<<n<<endl;
	}
	return 0;
}