#include <bits/stdc++.h>
using namespace std;
map<int,int> mp1,mp2;
int n,p,v,maxx,cnt,pv,cntt,minn;
pair<int,int> q[100010];
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p,&v);
		mp1[p]++;
		if(mp2[p]==0)
		{
			mp2[p]=v;
		}
		else
		{
			mp2[p]=min(mp2[p],v);
		}
	}
	cnt=-1,pv=-1;
	for(auto it1=mp1.begin(),it2=mp2.begin();it1!=mp1.end()&&it2!=mp2.end();it1++,it2++)
	{
//		if(cnt==-1)
//		{
//			cnt=it1->second,pv=it2->second;
//		}
//		else
//		{
//			if(pv>it2->second)
//			{
//				cnt+=it1->second;
//				pv=it2->second;
//			}
//			else
//			{
//				if()
//				maxx=max(maxx,cnt);
//				cnt=it1->second,pv=it2->second;
//			}
//		}
		q[++cntt].first=it1->second;
		q[cntt].second=it2->second;
	}
//	for(int i=cntt;i>=1;i--)
//	{
//		if(i==cntt) minn[i]=q[i].second;
//		else minn[i]=min(minn[i+1],q[i].second);
//	}
//	minn[n+1]=0x3f3f3f3f;
//	for(int i=1;i<=n;i++)
//	{
//		if(cnt==-1)
//		{
//			cnt=q[i].first,pv=q[i].second;
//		}
//		else
//		{
//			if(minn[i+1]<pv)
//			{
//				cnt+=q[i].first;
//				pv=q[i].second;
//			}
//			else
//			{
//				maxx=max(maxx,cnt);
//				pv=q[i].second;
//				cnt=q[i].first;
//			}
//		}
////		cout<<cnt<<" "<<maxx<<endl;
//	}
		for(int i=cntt;i>=1;i--)
		{
			if(cnt==-1)
			{
				cnt=q[i].first,minn=q[i].second;
			}
			else
			{
				if(q[i].second>minn)
				{
					minn=min(minn,q[i].second);
					cnt+=q[i].first;
				}
				else
				{
					maxx=max(maxx,cnt);
					minn=min(minn,q[i].second);
					cnt=q[i].first;
				}
			}
		}
	maxx=max(maxx,cnt);
	printf("%d",maxx);
	return 0;
}