#include <bits/stdc++.h>
using namespace std;
int n,m,f[100010],t,res,k,l,r,maxx,cnt;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		maxx=0;
		res=0;
		map<int,int> mp;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&k);
			mp[k]++;
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&f[i]);
		}
		sort(f+1,f+1+m);
		l=0,r=f[1];
		cnt=2;
		for(auto it=mp.begin();it!=mp.end();it++)
		{
			int fi=it->first,se=it->second;
			if(fi>l&&fi<r)
			{
				res+=se;
			}
			else if(fi>=r)
			{
				maxx=max(maxx,res);
				res=0;
				while(fi>=r)
				{
					l=r;
					if(cnt>m)
					{
						r=1e9+1;
					}
					else r=f[cnt];
					cnt++;
//					cout<<"le ri:"<<l<<" "<<r<<endl;
				}
				if(fi>l&&fi<r) res=se;
			}
//			cout<<res<<endl;
//			cout<<l<<" "<<r<<endl;
		}
		maxx=max(maxx,res);
		if(maxx==0)
		{
			puts("Impossible");
		}
		else
		{
			printf("%d\n",maxx);
		}
	}
	return 0;
}
/*
1 3 3
999999999 999999999 999999999
1 999999998 1000000000


1000
1 5
5
1 2 3 5 7
*/