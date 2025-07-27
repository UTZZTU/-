#include <bits/stdc++.h>
using namespace std;
int n,k,pos;
string t;
bool judge(string u)
{
	for(int k=1;k<u.size();k++)
	{
		int i=0,j=k;
		while(j<u.size()&&u[i]==u[j])
		{
			i++,j++;
		}
		if(j==u.size())
		{
			pos=k;
			return true;
		}
	}
	return false;
}
int main ()
{
	cin>>n>>k;
	getchar();
	cin>>t;
	if(judge(t))
	{
		string v;
		for(int i=n-pos;i<n;i++)
		v+=t[i];
		cout<<t;
		for(int i=1;i<k;i++)
		cout<<v;
	}
	else
	{
		for(int i=1;i<=k;i++)
		cout<<t;
	}
	return 0;
}