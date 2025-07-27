#include <bits/stdc++.h>
using namespace std;
string u;
int n;
bool judge(string u)
{
	for(int i=0;i<u.size();i++)
	{
		if(u[i]!='Y'&&u[i]!='e'&&u[i]!='s')
		return false;
	}
	for(int i=1;i<u.size();i++)
	{
		if(u[i]=='Y'&&u[i-1]!='s'||u[i]=='e'&&u[i-1]!='Y'||u[i]=='s'&&u[i-1]!='e')
		return false;
	}
	return true;
}
int main ()
{
	cin>>n;
	getchar();
	while(n--)
	{
		cin>>u;
		if(judge(u))
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
	return 0;
}