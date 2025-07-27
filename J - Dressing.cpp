#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,sum,p,a,b;
char u[100],v[100];
int main ()
{
	while(scanf("%lld %lld %lld",&n,&m,&k)!=EOF)
	{
		if(!n&&!m&&!k)
		break;
		unordered_map<int,int> mp1,mp2;
		sum=n*m*k;
		scanf("%lld",&p);
		getchar();
		while(p--)
		{
			scanf("%s %lld %s %lld",u,&a,v,&b);
			if(u[0]=='c')
			{
				mp1[b]++;
				sum-=k;
				sum+=mp2[b];
			}
			else
			{
				mp2[a]++;
				sum-=n;
				sum+=mp1[a];
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}