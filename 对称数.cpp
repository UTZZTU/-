#include <bits/stdc++.h>
using namespace std;
int t;
string u,v;
int main ()
{
	cin>>t;
	getchar();
	while(t--)
	{
		cin>>u;
		v=u;
		reverse(v.begin(),v.end());
		if(u==v)
		cout<<"yes"<<endl;
		else
		cout<<"no"<<endl;
	}
	return 0;
}