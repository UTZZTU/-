#include <bits/stdc++.h>
using namespace std;
vector<string> p;
int main ()
{
	string u,v;
	getline(cin,u);
	for(int i=0;i<u.size();i++)
	{
		while(u[i]!=' '&&i<u.size())
		{
			v+=u[i];
			i++;
		}
		p.push_back(v);
		v.clear();
	}
	reverse(p.begin(),p.end());
	for(int i=0;i<p.size();i++)
	{
		if(i!=0)
		cout<<" ";
		cout<<p[i];
	}
	return 0;
}