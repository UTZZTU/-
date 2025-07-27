#include <bits/stdc++.h>
using namespace std;
int t,ans,sum;
string u;
int main ()
{
	cin>>t;
	getchar();
	while(t--)
	{
		cin>>u;
		ans=0;
		sum=0;
		int i=0;
		while(i<u.size()&&u[i]=='0')
		i++;
		i++;
		for(i;i<u.size();i++)
		{
			if(u[i]=='0')
			ans++;
			else
			{
				sum+=ans;
				ans=0;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}