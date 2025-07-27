#include <bits/stdc++.h>
using namespace std;
string u,v,s;
int n;
int main ()
{
	cin>>u;
	scanf("%d",&n);
	getchar();
	for(int i=1;i<=n;i++)
	{
		cin>>v;
		s.clear();
		int p=v.find(u);
		for(int j=0;j<p;j++)
		{
			s+=v[j];
		}
		s+="Bruce12138";
		for(int j=p+u.size();j<v.size();j++)
		{
			s+=v[j];
		}
		cout<<s<<endl;
	}
	return 0;
}