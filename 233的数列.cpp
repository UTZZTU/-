#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A1,A2,B1,B2,C1,C2,a,b,c,d,e,f,u[110][110][110],k[5000010],q,cnt,ans,n,p;
int main ()
{
	cin>>n>>A1>>B1>>C1>>a>>b>>c>>d>>e>>f>>p;
	for(int i=1;i<=n;i++)
	{
	   A1%=p;
	   B1%=p;
	   C1%=p;
		if(u[A1][B1][C1])
		{
			k[++cnt]=(A1*B1%p*C1%p)%p;
			u[A1][B1][C1]++;
			k[cnt]+=k[cnt-1];
			k[cnt]%=p;
			q=i;
			int j;
			A2=(a*A1%p+b*B1%p)%p;
			B2=(c*A1%p+d*C1%p)%p;
			C2=(e*A1%p+f*B1%p)%p;
			A1=A2;
			B1=B2;
			C1=C2;
			for(j=i+1;j<=n&&u[A1][B1][C1]<=1;j++)
			{
				k[++cnt]=(A1*B1%p*C1%p)%p;
			    u[A1][B1][C1]++;
			    k[cnt]+=k[cnt-1];
			    k[cnt]%=p;
				A2=(a*A1%p+b*B1%p)%p;
			    B2=(c*A1%p+d*C1%p)%p;
			    C2=(e*A1%p+f*B1%p)%p;
			    A1=A2;
			    B1=B2;
			    C1=C2;
			}
			if(u[A1][B1][C1]>=2)
			{
				ans=(ans+k[q-1])%p;
				n-=q-1;
				ans=(ans+n/(j-q)%p*((k[cnt]-k[q-1]+p)%p)%p)%p;
			    n%=(j-q);
			    if(n)
			    {
			    	ans=(ans+(k[q+n-1]-k[q-1]+p)%p)%p;
				}
			    cout<<ans;
			    return 0;
			}
			else
			{
				cout<<k[cnt];
	            return 0;
			}
		}
		else
		{
			k[++cnt]=(A1*B1%p*C1%p)%p;
			u[A1][B1][C1]=1;
			k[cnt]+=k[cnt-1];
			k[cnt]%=p;
			A2=(a*A1%p+b*B1%p)%p;
			B2=(c*A1%p+d*C1%p)%p;
			C2=(e*A1%p+f*B1%p)%p;
			A1=A2;
			B1=B2;
			C1=C2;
		}
	}
	cout<<k[cnt];
	return 0;
}