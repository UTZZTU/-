#include <bits/stdc++.h>
using namespace std;
string s[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string f="fu",u;
int main ()
{
	cin>>u;
	for(int i=0;i<u.size();i++)
	{
		if(i) cout<<" ";
		if(u[i]=='-') cout<<f;
		else cout<<s[u[i]-'0'];
	}
	return 0;
}