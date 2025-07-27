#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
int main ()
{
	ll n1,n2,n,k;
	while(cin>>n1>>n2>>n)
	{
		if(n1==0&&n2==0&&n==0)
		break;
		else
		{
			ll sum=0;
			priority_queue<ll> q1,q2;
			for(int i=1;i<=n;i++)
			{
				scanf("%lld",&k);
				sum+=k;
				q1.push(k);
				if(q1.size()>n2)
				q1.pop();
				q2.push(-k);
				if(q2.size()>n1)
				q2.pop();
			}
			for(int i=1;i<=n2;i++)
			{
				sum-=q1.top();
				q1.pop();
			}
			for(int i=1;i<=n1;i++)
			{
				sum+=q2.top();
				q2.pop();
			}
			double s=sum*1.0/(n-n1-n2);
			printf("%.6f\n",s);
		}
	}
	return 0;
}