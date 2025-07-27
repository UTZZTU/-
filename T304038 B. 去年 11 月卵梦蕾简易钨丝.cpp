#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll res,n,q,k,maxx=-0x3f3f3f3f3f3f3f3f,minn=0x3f3f3f3f3f3f3f3f,fi,se,opt,x;
multiset<ll> st;
int main ()
{
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		maxx=max(maxx,k);
		minn=min(minn,k);
		st.insert(k);
	}
	for(auto it=st.begin();it!=st.end();it++)
	{
		if(it==st.begin())
		{
			fi=*it;
		}
		else
		{
			se=*it;
			res+=se-fi;
			fi=se;
		}
	}
	res+=maxx-minn;
	multiset<ll>::iterator it;
	while(q--)
	{
		scanf("%lld%lld",&opt,&x);
		if(opt==1)
		{
			it=st.lower_bound(x);
			if(it==st.end()||*it!=x)
			{
				printf("-1\n");
			}
			else
			{
				if(it==st.begin())
				{
					res-=*next(it)-*it;
					res-=maxx-*it;
					res+=maxx-*next(it);
					minn=*next(it);
					
				}
				else if(next(it)==st.end())
				{
					res-=*it-*prev(it);
					res-=*it-minn;
					res+=*prev(it)-minn;
					maxx=*prev(it);
				}
				st.erase(it);
				printf("%lld\n",res);
			}
		}
		else
		{
			if(x>=maxx)
			{
				res-=maxx-minn;
				res+=x-maxx;
				res+=x-minn;
				maxx=x;
			}
			else if(x<=minn)
			{
				res-=maxx-minn;
				res+=minn-x;
				res+=maxx-x;
				minn=x;
			}
			st.insert(x);
			printf("%lld\n",res);
		}
	}
	return 0;
}