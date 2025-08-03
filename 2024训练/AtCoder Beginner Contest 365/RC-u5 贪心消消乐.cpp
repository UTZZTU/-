#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,f[110][110],sum,t[110][110],res=1;
vector<pair<int,int>> vec;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>f[i][j];
			t[i][j]=t[i-1][j]+t[i][j-1]-t[i-1][j-1]+f[i][j];
			if(f[i][j]==0) vec.push_back({i,j});
		}
	}
	while(true)
	{
		res=0;
		int xx1=-1,xx2=-1,yy1=-1,yy2=-1;
		for(int jj1=1;jj1<=n;jj1++)
		{
			for(int ii1=1;ii1<=n;ii1++)
			{
				for(int jj2=jj1;jj2<=n;jj2++)
				{
					for(int ii2=ii1;ii2<=n;ii2++)
					{
						int num=t[ii2][jj2]-t[ii1-1][jj2]-t[ii2][jj1-1]+t[ii1-1][jj1-1];
//						cout<<num<<endl;
						if(num>res)
						{
//							auto it=st.lower_bound({ii1,jj1});
//							if(it!=st.end()&&*it.first<=ii2&&*it.second<=jj2)
//							{
//								continue;
//							}
							bool flag=false;
							for(int k=0;k<vec.size();k++)
							{
								if(vec[k].first>=ii1&&vec[k].first<=ii2&&vec[k].second>=jj1&&vec[k].second<=jj2)
								{
									flag=true;
									break;
								}
							}
							if(flag) continue;
							res=num;
							xx1=ii1,xx2=ii2,yy1=jj1,yy2=jj2;
						}
					}
				}
			}
		}
		if(res==0)
		{
			break;
		}
		cout<<"("<<yy1<<", "<<xx1<<") "<<"("<<yy2<<", "<<xx2<<") "<<res<<endl;
		sum+=res;
		for(int i=yy1;i<=yy2;i++)
		{
			deque<int> q;
			int zz=0;
			for(int j=xx1-1;j>=1;j--)
			{
				if(f[j][i]==0)
				{
					zz=j;
					break;
				}
				q.push_back(f[j][i]);
			}
			for(int j=xx2;j>zz;j--)
			{
				if(q.size())
				{
					f[j][i]=q.front();
					q.pop_front();
				}
				else
				{
					f[j][i]=0;
					vec.push_back({j,i});
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
//				cin>>f[i][j];
//cout<<f[i][j]<<" ";
				t[i][j]=t[i-1][j]+t[i][j-1]-t[i-1][j-1]+f[i][j];
			}
//			cout<<endl;
		}
	}
	cout<<sum<<endl;
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
