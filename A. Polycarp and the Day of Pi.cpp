#include <bits/stdc++.h>
using namespace std;
string s="314159265358979323846264338327",u;
int t;
int num()
{
	int res=0;
	for(int i=0;i<s.size()&&i<u.size()&&s[i]==u[i];i++)
	{
		res++;
	}
	return res;
}
int main ()
{
	cin>>t;
	getchar();
	while(t--)
	{
		cin>>u;
		cout<<num()<<endl;
	}
	return 0;
}