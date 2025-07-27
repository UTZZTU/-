#include <bits/stdc++.h>
using namespace std;
int ans=1,last;
map<char,int> mp;
string a;
int main ()
{
	getline(cin,a);
	for(int i=0;i<a.size();i++)
	mp[a[i]]=i+1;
	getline(cin,a);
	for(int i=0;i<a.size();i++)
	{
		if(i==0)
		last=a[i];
		else
		{
			if(a[i]==a[i-1])
			ans++;
			else if(mp[a[i]]<mp[a[i-1]])
			{
				ans++;
				last=a[i];
			}
		}
	}
	cout<<ans;
	return 0;
}