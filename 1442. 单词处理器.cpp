#include <bits/stdc++.h>
using namespace std;
vector<string> vec;
string u;
int n,k,js;
int main ()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>u;
		vec.push_back(u);
	}
	for(int i=0;i<vec.size();i++)
	{
		if(i==0)
		{
			cout<<vec[i];
			js=vec[i].size();
		}
		else
		{
			if(js+vec[i].size()>k)
			{
				cout<<endl;
				cout<<vec[i];
				js=vec[i].size();
			}
			else
			{
				cout<<" "<<vec[i];
				js+=vec[i].size();
			}
		}
	}
	return 0;
}