#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fr front
#define bk back
#define gl getline
int n,m,k,x,y,q,f[510][510],tt[20010];
string str,c;
map<string,int> mp1;
map<int,string> mp2;
map<string,bool> mp3;
map<int,pair<int,int>> mp4;
map<int,set<pair<int,int>>> mp5;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>str>>x>>y;
		mp1[str]=i;
		mp2[i]=str;
		if(f[x][y]==0)
		{
			f[x][y]=i;
			tt[i]=1;
			mp4[i]={x,y};
			mp5[i].insert({x,y});
		}
		else
		{
			if(mp2[f[x][y]]>str)
			{
				mp3[str]=true;
			}
			else
			{
				mp3[mp2[f[x][y]]]=true;
				f[x][y]=i;
				tt[i]=1;
				mp4[i]={x,y};
				mp5[i].insert({x,y});
			}
		}
	}
	cin>>q;
	while(q--)
	{
		cin>>str>>c;
		if(mp3[str]||mp1[str]==0)
		{
			cout<<"unexisted empire."<<endl;
		}
		else
		{
			x=mp4[mp1[str]].first,y=mp4[mp1[str]].second;
			if(c=="W")
			{
				x--;
			}
			else if(c=="A")
			{
				y--;
			}
			else if(c=="S")
			{
				x++;
			}
			else if(c=="D")
			{
				y++;
			}
			if(x<1||x>n||y<1||y>m)
			{
				cout<<"out of bounds!"<<endl;
			}
			else if(f[x][y]==0)
			{
				cout<<"vanquish!"<<endl;
				f[x][y]=mp1[str];
				tt[mp1[str]]++;
				mp4[mp1[str]]={x,y};
				mp5[mp1[str]].insert({x,y});
			}
			else if(f[x][y]==mp1[str])
			{
				cout<<"peaceful."<<endl;
				mp4[mp1[str]]={x,y};
			}
			else
			{
//				for(auto it=mp5.begin();it!=mp5.end();it++)
//				{
//					cout<<(it->second).size()<<endl;
//				}
//				return 0;
				string u=mp2[f[x][y]];
				if(tt[mp1[str]]>tt[f[x][y]])
				{
					tt[mp1[str]]+=tt[f[x][y]];
//					for(int i=1;i<=n;i++)
//					{
//						for(int j=1;j<=m;j++)
//						{
//							if(f[i][j]==f[x][y])
//							{
//								f[i][j]=mp1[str];
//							}
//						}
//					}
					set<pair<int,int>> st=mp5[f[x][y]];
					for(auto it=st.begin();it!=st.end();it++)
					{
						int xx=(*it).first,yy=(*it).second;
						f[xx][yy]=mp1[str];
//						cout<<xx<<" "<<yy<<endl;
						mp5[mp1[str]].insert({xx,yy});
					}
					mp4[mp1[str]]={x,y};
					cout<<str<<" wins!"<<endl;
					mp3[u]=true;
				}
				else if(tt[mp1[str]]<tt[f[x][y]])
				{
					tt[f[x][y]]+=tt[mp1[str]];
//					for(int i=1;i<=n;i++)
//					{
//						for(int j=1;j<=m;j++)
//						{
//							if(f[i][j]==mp1[str])
//							{
//								f[i][j]=f[x][y];
//							}
//						}
//					}
					set<pair<int,int>> st=mp5[mp1[str]];
					for(auto it=st.begin();it!=st.end();it++)
					{
						int xx=(*it).first,yy=(*it).second;
						f[xx][yy]=f[x][y];
//						cout<<xx<<" "<<yy<<endl;
						mp5[f[x][y]].insert({xx,yy});
					}
					cout<<u<<" wins!"<<endl;
					mp3[str]=true;
				}
				else if(str>u)
				{
					tt[mp1[str]]+=tt[f[x][y]];
//					for(int i=1;i<=n;i++)
//					{
//						for(int j=1;j<=m;j++)
//						{
//							if(f[i][j]==f[x][y])
//							{
//								f[i][j]=mp1[str];
//							}
//						}
//					}
					set<pair<int,int>> st=mp5[f[x][y]];
					for(auto it=st.begin();it!=st.end();it++)
					{
						int xx=(*it).first,yy=(*it).second;
						f[xx][yy]=mp1[str];
//						cout<<xx<<" "<<yy<<endl;
						mp5[mp1[str]].insert({xx,yy});
					}
					mp4[mp1[str]]={x,y};
					cout<<str<<" wins!"<<endl;
					mp3[u]=true;
				}
				else 
				{
					tt[f[x][y]]+=tt[mp1[str]];
//					for(int i=1;i<=n;i++)
//					{
//						for(int j=1;j<=m;j++)
//						{
//							if(f[i][j]==mp1[str])
//							{
//								f[i][j]=f[x][y];
//							}
//						}
//					}
					set<pair<int,int>> st=mp5[mp1[str]];
					for(auto it=st.begin();it!=st.end();it++)
					{
						int xx=(*it).first,yy=(*it).second;
						f[xx][yy]=f[x][y];
//						cout<<xx<<" "<<yy<<endl;
						mp5[f[x][y]].insert({xx,yy});
					}
					cout<<u<<" wins!"<<endl;
					mp3[str]=true;
				}
			}
		}
	}
	return 0;
}