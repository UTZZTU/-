#include <iostream>
using namespace std;
string s[110];
int n,m;
bool check(int k1,int k2,int k3,int k4)
{
	for(int i=k1;i<=k1+2;i++)
	{
		for(int j=k2;j<=k2+2;j++)
		{
			if(s[i][j]!='#') return false;
		}
	}
//	cout<<k1<<" "<<k2<<endl;
	for(int i=k3;i>=k3-2;i--)
	{
		for(int j=k4;j>=k4-2;j--)
		{
			if(s[i][j]!='#') return false;
		}
	}
//	cout<<k1<<" "<<k2<<endl;
	for(int i=k2;i<=k2+3;i++)
	{
		if(s[k1+3][i]!='.') return false;
	}
//	cout<<k1<<" "<<k2<<endl;
	for(int i=k1;i<=k1+3;i++)
	{
		if(s[i][k2+3]!='.') return false;
	}
//	cout<<k1<<" "<<k2<<endl;
	for(int i=k3;i>=k3-3;i--)
	{
		if(s[i][k4-3]!='.') return false;
	}
//	cout<<k1<<" "<<k2<<endl;
	for(int i=k4;i>=k4-3;i--)
	{
		if(s[k3-3][i]!='.') return false;
	}
//	cout<<k1<<" "<<k2<<endl;
	return true;
}
int main ()
{
	cin>>n>>m;
	getchar();
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(int k1=0;k1<n;k1++)
	{
		for(int k2=0;k2<m;k2++)
		{
			int k3=k1+8,k4=k2+8;
			if(k3>n||k4>m) continue;
			if(check(k1,k2,k3,k4))
			{
				cout<<k1+1<<" "<<k2+1<<endl;
			}
		}
	}
	return 0;
}