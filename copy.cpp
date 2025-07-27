#include <bits/stdc++.h>
using namespace std;
int n,m;
string u;
vector<string> vec;
int main ()
{
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++)
	{
		cin>>u;
        vec.push_back(u);
	}
	cin>>m;
	getchar();
	cout<<m<<endl;
	while(m--)
	{
		cin>>u;
		int pos;
		vector<string> v;
		v.push_back(u);
		for(int i=0;i<vec.size();i++)
		{
			if(vec[i]==u)
			{
				pos=i+1;
			}
			else v.push_back(vec[i]);
		}
		vec=v;
		cout<<pos<<endl;
	}
	return 0;
}