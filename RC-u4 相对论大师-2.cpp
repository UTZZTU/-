#include <bits/stdc++.h>
using namespace std;
string u,v,a,b,s[1010],uu,vv,aa,bb;
int n;
int main ()
{
	cin>>n;
	getchar();
	while(n--)
	{
		cin>>u>>a>>v>>b;
		if(u==v&&a!=b) uu=u,vv=v,aa=a,bb=b;
	}
	cout<<uu<<" "<<aa<<" "<<vv<<" "<<bb<<" = "<<uu<<" "<<aa<<" "<<vv<<" "<<bb<<endl;
	return 0;
}