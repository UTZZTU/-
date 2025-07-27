#include <bits/stdc++.h>
using namespace std;
string u;
int n,ans;
int main ()
{
	cin>>n;
	getchar();
	cin>>u;
	for(int i=0;i<u.size();i++)
	{
		if(u[i]=='<')
		ans++;
		else
		break;
	}
	for(int i=u.size()-1;i>=0;i--)
	{
		if(u[i]=='>')
		ans++;
		else
		break;
	}
	cout<<ans;
	return 0;
}