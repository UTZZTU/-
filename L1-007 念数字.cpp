#include <bits/stdc++.h>
using namespace std;
string a[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string u;
int main ()
{
	cin>>u;
	for(int i=0;i<u.size();i++)
	{
		if(i!=0)
		cout<<" ";
		if(u[i]=='-')
		cout<<"fu";
		else
		cout<<a[u[i]-'0'];
	}
	return 0;
}