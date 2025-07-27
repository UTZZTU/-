#include <bits/stdc++.h>
using namespace std;
int n,m;
string u[110];
int main ()
{
	cin>>n>>m;
	getchar();
	for(int i=0;i<n;i++)
	cin>>u[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<m;k++)
			{
				cout<<u[i][k]<<u[i][k];
			}
			cout<<endl;
		}
	}
	return 0;
}