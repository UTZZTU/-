#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
ll t,n,k,p[100010];
string s;
bool judge()
{
	int mid=n+1>>1;
	string v;
	for(int i=0;i<s.size();i++)
	{
		if(i<mid) v+=s[i];
		else v+=s[n-1-i];
	}
	return v<s;
}
int main ()
{
	scanf("%lld",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%lld%lld",&n,&k);
		getchar();
		cin>>s;
		p[0]=1;
		p[1]=k;
		for(int j=2;j<=n;j++)
		{
			p[j]=p[j-1]*k%MOD;
		}
		ll mid=n+1>>1,res=0;
		for(int i=0;i<mid;i++)
		{
			res+=(ll)(s[i]-'a')*(p[mid-i-1])%MOD;
			res%=MOD;
		}
		if(judge()) res=(res+1)%MOD;
		printf("Case #%lld: %lld\n",i,res);
	}
	return 0;
}