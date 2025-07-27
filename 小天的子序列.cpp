#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
const int N = 505;
int n,m,f[30][30][510],c[510][510];
string s;
int qmi(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
void init()
{
	for(int i=0;i<N;i++)
????{
????????for(int j=0;j<=i;j++)
????????{
????????????if(!j) c[i][j]=1;
????????????else c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
????????}
????}
}
int C(int x,int y)
{
	if(y>=x) return 1;
	else if(y==0) return 1;
	return c[x][y];
}
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	cin>>n;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=2;k<=n;k++)
			{
				if(k>j-i+1) break;
				f[s[i]-'a'][s[j]-'a'][k]+=C(j-i+1-2,k-2);
				f[s[i]-'a'][s[j]-'a'][k]%=mod;
//				if(s[i]=='x'&&s[j]=='y')
//				cout<<f[s[i]-'a'][s[j]-'a'][k]<<endl;
			}
		}
	}
	cin>>m;
	while(m--)
	{
		char c1,c2;
		int l;
		cin>>c1>>c2>>l;
		cout<<f[c1-'a'][c2-'a'][l]<<endl;
	}
	return 0;
}