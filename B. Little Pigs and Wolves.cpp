#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
char matrix[15][15];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) cin>>matrix[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(matrix[i][j]!='W') continue;  //如果不是狼就跳过
			if(matrix[i+1][j]=='P'||matrix[i-1][j]=='P'||matrix[i][j+1]=='P'||matrix[i][j-1]=='P') ans++;  //只能吃一头猪，所以只需要+1就好了
		}
	cout<<ans;
	return 0;
}