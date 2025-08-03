#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,x[200010],a[200010],xh[200010],cd[200010],vis[200010],fnl[200010],cnt;
vector<int> vec[200010];
void solve()
{
	cin>>n>>k;
	memset(xh,-1,sizeof xh);
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vector<pair<int,int>> vec;
		vec.push_back({i,x[i]});
		vis[i]=1;
		int nxt=x[i];
		while(1)
		{
			if(!vis[nxt])
			{
				vec.push_back({nxt,x[nxt]});
				vis[nxt]=1;
				nxt=x[nxt];
			}
			else if(xh[nxt]==-1)
			{
				int pos=-1;
				for(int j=0;j<vec.size();j++)
				{
					if(vec[j].first==nxt)
					{
						pos=j;
						break;
					}
				}
				int pp=vec.size()-pos;
				for(int j=0;j<vec.size();j++)
				{
					cd[vec[j].first]=pp;
				}
				for(int j=0;j<vec.size();j++)
				{
					if(j<=pos)
					{
						xh[vec[j].first]=pos-j;
					}
					else
					{
						xh[vec[j].first]=pp-(j-pos);
					}
				}
				for(int j=0;j<vec.size();j++)
				{
					ll op=vec[j].first;
					ll p=k;
					if(j<=pos)
					{
						if(p<xh[op]+cd[op])
						{
							fnl[op]=vec[j+p].first;
						}
						else
						{
							p-=xh[op];
							p%=cd[op];
							p+=xh[op];
							fnl[op]=vec[j+p].first;
						}
					}
					else
					{
						if(p<xh[op]+cd[op])
						{
							if(j+p<vec.size())
							fnl[op]=vec[j+p].first;
							else fnl[op]=vec[j+p-vec.size()+pos].first;
						}
						else
						{
							p-=xh[op];
							p%=cd[op];
							p+=xh[op];
							if(j+p<vec.size())
							fnl[op]=vec[j+p].first;
							else fnl[op]=vec[j+p-vec.size()+pos].first;
						}
					}
					
				}
				break;
			}
			else
			{
				for(int j=0;j<vec.size();j++)
				{
					xh[vec[j].first]=(vec.size()-j)+xh[nxt];
					cd[vec[j].first]=cd[nxt];
				}
				for(int j=0;j<vec.size();j++)
				{
					ll p=k;
					if(p<)
				}
				break;
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		ll p=k,nxt=i;
//		if(p>=xh[i]+cd[i])
//		{
//			p-=xh[i];
//			p%=cd[i];
//			p+=xh[i];
//		}
//		while(p--)
//		{
//			nxt=x[nxt];
//		}
//		fnl[i]=a[nxt];
//	}
	for(int i=1;i<=n;i++)
	{
		cout<<fnl[i]<<" ";
	}
	cout<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}