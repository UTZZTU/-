#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int> mp;
int n,m,cnt=100000,f[300100];
vector<int> vec[300010];
string a,b;
bool is_num(string s)
{
	if(s[0]>='0'&&s[0]<='9') return true;
	return false;
}
int get_num(string s)
{
	int res=0;
	for(int i=0;i<s.size();i++)
	{
		res=res*10+s[i]-'0';
	}
	return res;
}
int bfs(int x)
{
	queue<int> q;
	int res=0;
	q.push(x);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(u<=n)
		res++;
		for(int i=0;i<vec[u].size();i++)
		{
			q.push(vec[u][i]);
		}
	}
	return res;
}
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=300000;i++)
	{
		f[i]=i;
	}
	getchar();
	while(m--)
	{
		cin>>a>>b;
		if(is_num(a))
		{
			int pos=get_num(a);
			if(mp[b]==0) mp[b]=cnt++;
			f[pos]=mp[b];
			vec[mp[b]].push_back(pos);
		}
		else
		{
			if(mp[a]==0) mp[a]=cnt++;
			if(mp[b]==0) mp[b]=cnt++;
			f[mp[a]]=mp[b];
			vec[mp[b]].push_back(mp[a]);
		}
	}
	while(cin>>a)
	{
		if(a=="E") break;
		else if(a=="T")
		{
			int num,pos;
			cin>>num>>b;
			pos=mp[b];
			if(f[num]==num)
			{
				f[num]=pos;
				vec[pos].push_back(num);
			}
			else
			{
				vector<int> v;
				for(int i=0;i<vec[f[num]].size();i++)
				{
					if(vec[f[num]][i]!=num)
					{
						v.push_back(vec[f[num]][i]);
					}
				}
				vec[f[num]]=v;
				f[num]=pos;
				vec[pos].push_back(num);
			}
		}
		else
		{
			cin>>b;
			cout<<bfs(mp[b])<<endl;
		}
	}
	return 0;
}