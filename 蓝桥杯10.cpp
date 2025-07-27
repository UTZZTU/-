#include <bits/stdc++.h>
using namespace std;
string u,mn;
int sz,maxx;
vector<int> vec[6];
int main ()
{
	cin>>u;
	for(int i=0;i<u.size();i++)
	vec[u[i]-'A'].push_back(i);
	int i=0;
	while(vec[i].size()==0)
	i++;
	if(vec[i].size()==u.size())
	{
		cout<<0;
		return 0;
	}
	if(vec[i].size()<=100000)
	maxx=500;
	else
	maxx=100;
	for(int j=0;j<vec[i].size();j++)
	{
		string v;
		int n=vec[i][j];
		while(v.size()<maxx)
		{
			v+=u[n];
			n+=(u[n]-'A'+1);
			n%=u.size();
		}
		if(j==0)
		{
			mn=v;
			sz=vec[i][j];
		}
		else
		{
			if(v<mn)
			{
				mn=v;
				sz=vec[i][j];
			}
		}
	}
	cout<<sz;
	return 0;
}