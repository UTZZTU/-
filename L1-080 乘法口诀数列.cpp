#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int n1,n2,n,pos=0;
int main ()
{
	cin>>n1>>n2>>n;
	vec.push_back(n1);
	vec.push_back(n2);
	while(vec.size()<n)
	{
		int x=vec[pos],y=vec[pos+1];
		x*=y;
		string u=to_string(x);
		for(int i=0;i<u.size();i++)
		{
			vec.push_back(u[i]-'0');
		}
		pos++;
	}
	for(int i=0;i<n;i++)
	{
		if(i) cout<<" ";
		cout<<vec[i];
	}
	return 0;
}