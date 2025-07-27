#include <bits/stdc++.h>
using namespace std;
string u,v;
int main ()
{
	cin>>u;
	for(int i=0;i<u.size();i++)
	{
		v+=u[i];
		while(v.size()>=2&&v[v.size()-2]==v[v.size()-1])
		{
			v.erase(v.begin()+v.size()-1);
			v.erase(v.begin()+v.size()-1);
		}
	}
	cout<<v;
	return 0;
}