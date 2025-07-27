#include <bits/stdc++.h>
using namespace std;
string s="codeforces",w;
int t;
int main ()
{
	cin>>t;
	getchar();
	while(t--)
	{
		cin>>w;
		if(s.find(w)!=-1)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
	return 0;
}