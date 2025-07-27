#include <bits/stdc++.h>
using namespace std;
int t,n,qz[200010],hz[200010],maxx;
string s;
int main ()
{
	cin>>t;
	while(t--)
	{
		maxx=0;
		cin>>n;
		getchar();
		cin>>s;
		set<char> st1,st2;
		for(int i=0;i<s.size();i++)
		{
			st1.insert(s[i]);
			qz[i+1]=st1.size();
		}
		for(int i=s.size()-1;i>=0;i--)
		{
			st2.insert(s[i]);
			hz[i+1]=st2.size();
		}
		maxx=max(qz[s.size()],hz[1]);
		for(int i=1;i<s.size();i++)
		{
			maxx=max(maxx,qz[i]+hz[i+1]);
		}
		cout<<maxx<<endl;
	}
	return 0;
}