#include <iostream>
#include <map>
using namespace std;
map<string,int> mp;
string u[1010],v;
int n,m,num;
int main ()
{
	cin>>n>>m;
	getchar();
	for(int i=1;i<=n;i++)
	{
		cin>>u[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>v;
		mp[v]=1;
	}
	for(int i=1;i<=n;i++)
	{
		v=u[i].substr(3,3);
		num+=mp[v];
	}
	cout<<num;
	return 0;
}