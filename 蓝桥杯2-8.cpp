#include <bits/stdc++.h>
using namespace std;
bool judgesame(string u)
{
	string v=u;
	reverse(v.begin(),v.end());
	if(v==u)
	return true;
	else
	return false;
}
string u,v;
bool check(int x)
{
	int i,j;
	for(i=x,j=0;i<u.size()&&j<v.size()&&u[i]==v[j];i++,j++)
	;
	if(i==u.size())
	return true;
	else
	return false;
}
int main ()
{
	cin>>u;
	if(judgesame(u))
	{
		cout<<u;
		return 0;
	}
	v=u;
	reverse(v.begin(),v.end());
	int i,j;
	for(i=1;i<u.size();i++)
	{
		if(check(i))
		{
			for(int j=u.size()-i;j<v.size();j++)
			u+=v[j];
			cout<<u;
			return 0;
		}
	}
	return 0;
}