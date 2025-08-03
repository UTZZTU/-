#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
string s;
int p[26],cnt,maxx,f[26];
//struct node
//{
//	char c;
//	int sum;
//	inline bool operator<(const node&a)const
//	{
//		return sum<a.sum;
//	}
//};
void solve()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		p[s[i]-'a']++;
		maxx=max(maxx,p[s[i]-'a']);
//		if(p[s[i]-'a']==1) cnt++;
	}
	if(maxx==1)
	{
		cout<<s.size()<<endl;
		cout<<s<<endl;
	}
	else
	{
		int bz=(s.size()-1)/(maxx-1);
		cout<<bz<<endl;
		memset(f,-1,sizeof f);
//		priority_queue<node> q,l;
//		for(int i=0;i<26;i++)
//		{
//			if(p[i])
//			{
//				q.push({'a'+i,p[i]});
//			}
//		}
		int index,pp,fp=1;
		while(1)
		{
			index=-1,pp=0;
			for(int i=0;i<26;i++)
			{
				if(!p[i]) continue;
				if(f[i]==-1||fp-f[i]>=bz)
				{
					if(p[i]>pp)
					{
						pp=p[i];
						index=i;
					}
				}
			}
			if(index==-1) break;
			else
			{
				cout<<(char)('a'+index);
				p[index]--;
				f[index]=fp;
			}
			fp++;
		}
		
	}
	
	
//	cout<<cnt<<endl;
//	for(int i=0;i<26;i++)
//	{
//		if(p[i])
//		{
//			p[i]--;
//			cout<<(char)('a'+i);
//		}
//	}
//	for(int i=0;i<26;i++)
//	{
//		while(p[i])
//		{
//			p[i]--;
//			cout<<(char)('a'+i);
//		}
//	}
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