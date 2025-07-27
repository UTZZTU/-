#include <bits/stdc++.h>
using namespace std;
int t,n,m,flag;
string u,v;
void judge()
{
	flag=0;
	for(int i=1;i<m;i++)
	{
		if(v[i]==v[i-1])
		{
			flag=1;
			break;
		}
	}
}
bool check()
{
	for(int i=0;i<n-1;i++)
	{
		if(u[i]==u[i+1])
		{
			if(flag) return false;
			if(u[i]=='0')
			{
				if(v[0]!='1'||v[m-1]!='1') return false;
			}
			else
			{
				if(v[0]!='0'||v[m-1]!='0') return false;
			}
		}
	}
	return true;
}
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		cin>>u>>v;
		judge();
		if(check()) puts("Yes");
		else puts("No");
	}
	return 0;
}