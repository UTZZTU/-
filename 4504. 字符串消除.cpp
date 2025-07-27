#include <bits/stdc++.h>
using namespace std;
string u,v;
int ans;
int main ()
{
	cin>>u;
	for(int i=0;i<u.size();i++)
	{
		v+=u[i];
		while(v.size()>=2&&v[v.size()-1]==v[v.size()-2])
		{
			v.erase(v.begin()+v.size()-2,v.end());
			ans++;
		}
	}
	if(ans&1)
	cout<<"Yes";
	else
	cout<<"No";
	return 0;
}