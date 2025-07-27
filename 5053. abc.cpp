#include <bits/stdc++.h>
using namespace std;
int t,n;
string s="abc";
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++) cout<<s[i%3];
		cout<<endl;
	}
	return 0;
}