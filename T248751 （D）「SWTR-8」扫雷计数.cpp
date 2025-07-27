#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 998244353;
string a[510];
int s,n,m;
ll f[510][510];
ll dfs(int x,int y)
{
	if(f[x][y])
	return f[x][y];
	else
	{
		if(x>y)
		return dfs(x-1,y)%INF*dfs(x-1,y)%INF;
		else
		return dfs(x,y-1)%INF*dfs(x,y-1)%INF;
	}
}
int main ()
{
	f[1][2]=f[2][1]=f[2][2]=f[1][1]=2;
	scanf("%d",&s);
	scanf("%d %d",&n,&m);
	getchar();
	for(int i=1;i<=n;i++)
	getline(cin,a[i]);
	if(f[n][m])
	cout<<f[n][m]<<endl;
	else
	cout<<dfs(n,m);
	return 0;
}