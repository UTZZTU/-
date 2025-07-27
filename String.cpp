#include <bits/stdc++.h>
using namespace std;
int ans,n;
int main ()
{
	cin>>n;
	getchar();
	string u,v;
	getline(cin,u);
	getline(cin,v);
	int i=n-1;
	for(int j=n-1;j>=0;j--)
	{
		if(u[j]==v[i]&&i>=0)
		{
			ans++;
			i--;
		}
	}
	cout<<n-ans;
	return 0;
}