#include <bits/stdc++.h>
using namespace std;
set<string> p;
int main ()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		if(p.find(s)!=p.end())
		cout<<"Hi "<<s<<"! Glad to see you again!";
		else
		{
			cout<<"Hello "<<s<<", how are you?";
			p.insert(s);
		}
		if(i!=n)
		cout<<endl;
	}
	return 0;
}