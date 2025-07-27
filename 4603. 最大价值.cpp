#include <bits/stdc++.h>
using namespace std;
int t,n,maxx,ans;
string u;
int main ()
{
	cin>>t;
	while(t--)
	{
		maxx=0;
		cin>>n;
		getchar();
		cin>>u;
		int i=0;
		while(i<n&&u[i]=='P')
		i++;
		for(i;i<n;i++)
		{
			ans=0;
			while(i<n&&u[i]=='A')
			i++;
			while(i<n&&u[i]=='P')
			{
				ans++;
				i++;
			}
			maxx=max(maxx,ans);
		}
		cout<<maxx<<endl;
	}
	return 0;
}