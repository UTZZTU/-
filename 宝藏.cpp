#include<bits/stdc++.h>
#define ll long long
using namespace std;
int ch[11];
ll dp[21][11],n,m,k;
ll read(){
	ll x=0,w=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*w;
}

ll query(ll len,ll pre,ll f,ll limit){//len表示长度，pre表示前驱，f表示判断前导0，limit表示会不会受到限制 
	ll ans=0;
	if(len<1)return 1;//如果长度被枚举完了说明合法，作为一个有贡献的数字返回 
	if(!limit&&f&&dp[len][pre])return dp[len][pre];//如果没有限制的情况下，返回已经记录好的数组答案 
	ll maxx=limit==1?ch[len]:9;//判断前面是否有最大枚举范围的限制，是则为ch[len]，否则为9 
	for(ll i=0;i<=maxx;i++){
		if(abs(i-pre)>=5)//如果相邻位的差值的绝对值大于等于5 
		ans+=query(len-1,i,f||i!=0,limit&&i==maxx);//递归符合条件的情况，记得把前导0等条件更新 
		else if(!f)//因为前面是前导0所以跟相邻位无关直接往后面做就好 
		ans+=query(len-1,i,i!=0,limit&&i==maxx);
	}
	if(!limit&&f)dp[len][pre]=ans;//在不受限制的情况下记忆化当前数组dp 
	return ans;
}

ll solve(ll x){//把当前数分解到数组 
	k=0;
	while(x){
		ch[++k]=x%10;
		x/=10;
	}
	return query(k,0,0,1);
}

int main(){
	n=read();m=read();
	printf("%lld",solve(m)-solve(n-1));
	return 0;
}