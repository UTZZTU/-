#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[1000010],ans,t,n,k1,k2,p;
double s1,s2;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&f[i]);
			f[i]+=f[i-1];
		}
		scanf("%lld %lld %lld",&k1,&k2,&p);
		string u(k2-1,'0');
		for(int i=k2;i<=n;i++)
		{
			s1=f[i]-f[i-k1];
			s2=f[i]-f[i-k2];
			if(s1*1.0/k1<s2*1.0/k2*p/100.0)
			u+='1';
			else
			u+='0';
		}
		cout<<u<<endl;
	}
	return 0;
}