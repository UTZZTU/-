#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll dp[110][100][2];
int data[110];
ll dfs(int len,int sum,bool flag)
{
	if(len==0)return sum==k;
	//if(sum>k)return 0;
	if(dp[len][sum][flag]!=-1)return dp[len][sum][flag];
	int max1=flag?data[len]:1; //这个是取当前能取到的最大值 
	ll ans=0;
	for(int i=0;i<=max1;i++)
	{
		ans+=dfs(len-1,sum+(i==1),flag&(i==max1));
	}
	return dp[len][sum][flag]=ans;
}
ll chaifen(ll nn)
{
	int len=0;
	while(nn>=1)
	{
		data[++len]=nn%2;
		nn/=2;	
	}
	memset(dp,-1,sizeof(dp));
	return dfs(len,0,1);
}
int main()
{
	scanf("%lld %lld",&n,&k);
    cout<<1ll*chaifen(n)<<endl;
    return 0;
} 