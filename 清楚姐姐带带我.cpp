#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 19980829;
ll ans,n,a,b,res=0;
double s;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		if(b==1)
		res+=a;
		else
		{
			s=(a*1.0/(b-1)-res)/INF;
			if(s>ans)
			res+=a;
			else
			{
				ans+=b/INF;
				b%=INF;
				res*=b;
			}
		}
		ans+=res/INF;
		res%=INF;
	}
	cout<<res%INF;
	return 0;
}