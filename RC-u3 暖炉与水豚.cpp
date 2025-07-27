#include <bits/stdc++.h>
using namespace std;
int n,m,ff;
string s[1010];
vector<pair<int,int>> vec;
int main ()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i][j]=='w')
			{
				int flag=0;
				for(int k1=-1;k1<=1;k1++)
				{
					for(int k2=-1;k2<=1;k2++)
					{
						int dx=k1+i,dy=k2+j;
						if(dx>=0&&dx<n&&dy>=0&&dy<m&&s[dx][dy]=='m')
						{
							flag=1;
							break;
						}
					}
					if(flag==1) break;
				}
				if(!flag)
				{
					for(int k1=-1;k1<=1;k1++)
					{
						for(int k2=-1;k2<=1;k2++)
						{
							int dx=k1+i,dy=k2+j;
							if(dx>=0&&dx<n&&dy>=0&&dy<m&&s[dx][dy]=='.')
							{
								vec.push_back({dx,dy});
							}
						}
					}
				}
			}
		}
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++)
	{
		int flag=0;
		for(int k1=-1;k1<=1;k1++)
		{
			for(int k2=-1;k2<=1;k2++)
			{
				int dx=k1+vec[i].first,dy=k2+vec[i].second;
				if(dx>=0&&dx<n&&dy>=0&&dy<m&&s[dx][dy]=='c')
				{
					flag=1;
				}
			}
		}
		if(!flag)
		{
			cout<<vec[i].first+1<<" "<<vec[i].second+1<<endl;
			ff=1;
		}
	}
	if(!ff)
	{
		cout<<"Too cold!";
	}
	return 0;
}
