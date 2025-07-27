#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
int s,n,q,w,b1,b2,inc,decv,f[100010],op,bj[100010],l,h,pd,ans,pos;
int main ()
{
	scanf("%d",&s);
	scanf("%d %d %d %d %d %d %d",&n,&q,&w,&b1,&b2,&inc,&decv);
	for(int i=1;i<=n;i++)
	scanf("%d",&f[i]);
	while(scanf("%d",&op)!=EOF)
	{
		if(op==2)
		scanf("%d",&w);
		else if(op==1)
		{
			ans=-0x3f3f3f3f;
			vector<int> vec;
			scanf("%d %d",&l,&h);
			memset(bj,0,sizeof(bj));
			for(int i=1,k;i<=l;i++)
			{
			    scanf("%d",&k);
			    bj[k]=1;
			}
			for(int i=1,k;i<=h;i++)
			{
				scanf("%d",&k);
			    bj[k]=-1;
			    vec.push_back(k);
			}
			sort(vec.begin(),vec.end());
			if(vec.empty())
			vec.push_back(0);
				for(int i=1;i<vec[0];i++)
			{
				pos=0;
				pd=0;
				for(int j=i;j<vec[0];j++)
				{
					if(abs(f[j]-w)>b2)
					pos+=decv;
					else if(abs(f[j]-w)<=b1)
					pos+=inc;
					if(bj[j]==1)
					pd=1;
					if(pd)
					ans=max(ans,pos);
				}
			}
			for(int i=0;i<vec.size()-1;i++)
			{
				for(int j=vec[i]+1;j<vec[i+1];j++)
				{
					pos=0;
				    pd=0;
				for(int k=j;k<vec[i+1];k++)
				{
					if(abs(f[k]-w)>b2)
					pos+=decv;
					else if(abs(f[k]-w)<=b1)
					pos+=inc;
					if(bj[k]==1)
					pd=1;
					if(pd)
					ans=max(ans,pos);
				}
				}
			}
			for(int i=vec[vec.size()-1]+1;i<=n;i++)
			{
				pos=0;
				pd=0;
				for(int j=i;j<=n;j++)
				{
					if(abs(f[j]-w)>b2)
					pos+=decv;
					else if(abs(f[j]-w)<=b1)
					pos+=inc;
					if(bj[j]==1)
					pd=1;
					if(pd)
					ans=max(ans,pos);
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}