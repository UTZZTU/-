#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,minn;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		minn=20;
		scanf("%lld",&n);
		for(int i=0;i<20;i++)
		{
			int k=n+i,cnt1=0;
			while(k%2==0) cnt1++,k>>=1;
			cnt1=min((ll)20,(ll)cnt1);
			minn=min(minn,(ll)20-cnt1+i);
		}
		cout<<minn<<endl;
	}
	return 0;
}