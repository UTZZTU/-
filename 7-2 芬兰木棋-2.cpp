#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<double,ll> mp1,mp2,mp3,mp4;
ll cnt1,cnt2,n,sum1,sum2;
struct node
{
	ll x,y,pos;
	ll sx;
}s[100010];
bool cmp(node x,node y)
{
	return x.sx<y.sx;
}
int main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&s[i].x,&s[i].y,&s[i].pos);
		s[i].sx=s[i].x*s[i].x+s[i].y*s[i].y;
		sum1+=s[i].pos;
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(s[i].x==0)
		{
			if(cnt1==0)
			{
				sum2++;
				cnt1=s[i].pos;
			}
			else
			{
				if(s[i].pos!=1) sum2++;
				else
				{
					if(cnt1!=1) sum2++;
				}
				cnt1=s[i].pos;
			}
		}
		else if(s[i].y==0)
		{
			if(cnt2==0)
			{
				sum2++;
				cnt2=s[i].pos;
			}
			else
			{
				if(s[i].pos!=1) sum2++;
				else
				{
					if(cnt2!=1) sum2++;
				}
				cnt2=s[i].pos;
			}
		}
		else if(s[i].x>0&&s[i].y>0)
		{
			double k=s[i].y*1.0/s[i].x;
			if(mp1[k]==0)
			{
				sum2++;
				mp1[k]=s[i].pos;
			}
			else
			{
				if(s[i].pos!=1) sum2++;
				else
				{
					if(mp1[k]!=1) sum2++;
				}
				mp1[k]=s[i].pos;
			}
		}
		else if(s[i].x>0&&s[i].y<0)
		{
			double k=s[i].y*1.0/s[i].x;
			if(mp2[k]==0)
			{
				sum2++;
				mp2[k]=s[i].pos;
			}
			else
			{
				if(s[i].pos!=1) sum2++;
				else
				{
					if(mp2[k]!=1) sum2++;
				}
				mp2[k]=s[i].pos;
			}
		}
		else if(s[i].x<0&&s[i].y>0)
		{
			double k=s[i].y*1.0/s[i].x;
			if(mp3[k]==0)
			{
				sum2++;
				mp3[k]=s[i].pos;
			}
			else
			{
				if(s[i].pos!=1) sum2++;
				else
				{
					if(mp3[k]!=1) sum2++;
				}
				mp3[k]=s[i].pos;
			}
		}
		else
		{
			double k=s[i].y*1.0/s[i].x;
			if(mp4[k]==0)
			{
				sum2++;
				mp4[k]=s[i].pos;
			}
			else
			{
				if(s[i].pos!=1) sum2++;
				else
				{
					if(mp4[k]!=1) sum2++;
				}
				mp4[k]=s[i].pos;
			}
		}
	}
	printf("%lld %lld\n",sum1,sum2);
	return 0;
}