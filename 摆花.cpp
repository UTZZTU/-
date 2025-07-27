#include <algorithm>
#include<iostream>
using namespace std;
int A[105][105];
int a[105];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	A[0][0]=1; 
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			for(int k=0;k<=min(a[i],j);k++) 
			{
				A[i][j]=(A[i][j]+A[i-1][j-k])%1000007;
			}
		}
	}
	cout<<A[n][m]%1000007<<endl;
    return 0;
}
