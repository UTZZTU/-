#include<cstdio>
#include<iostream>
#define ull unsigned long long
using namespace std;
#define int long long
int t,k=1e9+7,k1,n,m,c[2001][2001],s[2001][2001];
int read()
{
	int res=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') res=(res<<1)+(res<<3)+(ch-'0'),ch=getchar();
	return res;
}
signed main()
{
//	freopen("problem.in","r",stdin);
//	freopen("problem.out","w",stdout);
//	t=read();k=read();
	c[1][1]=c[0][0]=1;
	for (int i=2;i<=2000;++i)
		for (int j=1;j<=min((int)2000,i);++j)
			c[i][j]=(c[i-1][j-1]%k+j*c[i-1][j]%k)%k;
//	for (int i=0;i<=2000;++i)
//		for (int j=0;j<=i;++j)
//			if (c[i][j]==0) s[i][j]=1;
//	for (int i=1;i<=2000;++i)
//		s[i][0]+=s[i-1][0],s[0][i]+=s[0][i-1];
//	for (int i=1;i<=2000;++i)
//		for(int j=1;j<=2000;++j)
//			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	while (1)
	{
		n=read();m=read();
		printf("%lld\n",c[n][m]);
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;	
} 
