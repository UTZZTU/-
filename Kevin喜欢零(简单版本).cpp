#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,k,f[200010],five[200010],two[200010];
ll res,ans;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&f[i]);
			ll j=f[i];
			res=0;
			while(j%2==0)
			{
				res++;
				j/=2;
			}
			two[i]=res;
			two[i]+=two[i-1];
			res=0;
			while(j%5==0)
			{
				res++;
				j/=5;
			}
			five[i]=res;
			five[i]+=five[i-1];
		}
		for(int i=1;i<=n;i++)
		{
			int x=two[i-1],y=five[i-1];
			int pos1=lower_bound(two+1,two+1+n,x+k)-two;
			int pos2=lower_bound(five+1,five+1+n,y+k)-five;
			int pos3=lower_bound(two+1,two+1+n,x+k+1)-two;
			int pos4=lower_bound(five+1,five+1+n,y+k+1)-five;
//			printf("%d %d %d %d\n",pos1,pos2,pos3,pos4);
            ans+=(max(pos3,pos4)-max(max(pos1,pos2),i));
		}
		printf("%lld\n",ans);
	}
	return 0;
}

/*1
10 4
2 8 5 15 16 125 11 75 12 9
*/