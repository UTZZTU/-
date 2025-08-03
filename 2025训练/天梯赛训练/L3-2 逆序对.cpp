#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}());
int dp[1005][1005],fp[1005][1005];
int num[1005],nn[1005]; 
void solve()
{
	int n;
	cin>>n;
	for(int i = 0; i < n; i ++){
		scanf("%d",&num[i]);
		nn[n-i-1]=num[i];
	}

	for(int i = 1; i < n; i ++){
		dp[0][i] = dp[0][i-1];
		for(int j = 0; j < i; j ++){
			if(num[i] < num[j])
				dp[0][i] ++;
		}
	}
//	for(int i=n-2;i>=0;i--)
//	{
//		fp[i][n-1]=fp[i+1][n-1];
//		for(int j=n-1;j>i;j--)
//		{
//			if(num[j]<num[i])
//			{
//				dp[i][n-1]++;
//			}
//		}
//	}

	for(int i = 1; i < n; i ++){
		fp[0][i] = fp[0][i-1];
		for(int j = 0; j < i; j ++){
			if(nn[i] < nn[j])
				fp[0][i] ++;
		}
	}
	int jichu=0; 
	for(int i = 1; i < n; i ++){
		if( num[i] < num[i-1] ) jichu = 1;
		else jichu = 0;
		for(int j = i + 1;j < n; j ++){
			if( num[j] < num[i-1] ) jichu ++;
			dp[i][j] = dp[i-1][j] - jichu;
		}
	}
	
//	jichu=0;
//	for(int i=n-2;i>=0;i--)
//	{
//		if(num[i]>num[i+1]) jichu=1;
//		else jichu=0;
//		for(int j=i-1;j>=0;j--)
//		{
//			if(num[j]>num[i+1]) jichu++;
//			dp[i][j]=dp[j][i+1]-jichu;
//		}
//	}

	jichu=0; 
	for(int i = 1; i < n; i ++){
		if( nn[i] < nn[i-1] ) jichu = 1;
		else jichu = 0;
		for(int j = i + 1;j < n; j ++){
			if( nn[j] < nn[i-1] ) jichu ++;
			fp[i][j] = fp[i-1][j] - jichu;
		}
	}
	
	int pp=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(pp==-1) pp=1;
			else cout<<" ";
			cout<<dp[0][n-1]-dp[i-1][j-1]+fp[n-j][n-i];
		}
	}
//	int m;
//	cin>>m;
//	for(int i=1;i<=m;i++)
//	{
//		int l,r;
//		cin>>l>>r;
//		cout<<dp[l-1][r-1]<<endl;
//	}
}
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
// 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
int main ()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}