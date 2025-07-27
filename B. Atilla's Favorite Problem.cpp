#include <bits/stdc++.h>
using namespace std;
int t,n,maxx;
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
		for(int i=0;i<n;i++)
		maxx=max(maxx,u[i]-'a'+1);
		cout<<maxx<<endl;
	}
	return 0;
}