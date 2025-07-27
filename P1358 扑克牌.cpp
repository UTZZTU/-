#include<bits/stdc++.h>
using namespace std;
long long n,m,s=1,t;
long long a[10005][105];
int main()
{
	cin>>n>>m;
	a[0][0]=1;
	for(int i=1;i<=10000;i++)
		for(int j=0;j<=100;j++)
			a[i][j]=(a[i-1][j-1]+a[i-1][j])%10007;
	for(int i=1;i<=m;i++){
		cin>>t;
		s=s*a[n][t]%10007;
		n-=t;//牌已经被抽走了，要减掉
	}
	cout<<s;
	return 0;
}