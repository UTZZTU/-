#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],m,k,pre,flag=1,tt; 
map<int,set<pair<int,int> > >mp1,mp2;
bool check1(int pre)
{
	int pp=1;
	for(auto it=mp2[pre].begin();it!=mp2[pre].end();it++)
	{
		if(it->first-pp>2) return false;
		pp=it->second;
	}
	if(n-pp>2) return false;
	return true;
}
bool check2(int pre)
{
	int res=0,pp=1;
	for(auto it=mp2[pre].begin();it!=mp2[pre].end();it++)
	{
		res+=it->first-pp;
		if(res>1) return false;
		pp=it->second;
	}
	if(n-pp+res>1) return false;
	return true;
}
set<pair<int,int> >get_set(int x)
{
	int pp=-1;
	set<pair<int,int> >st;
	if((*(mp2[x].begin())).first!=1)
	{
		st.insert({1,(*(mp2[x].begin())).first-1});
	}
	if((*(mp2[x].rbegin())).second!=n)
	{
		st.insert({(*(mp2[x].rbegin())).second+1,n});
	}
	for(auto it=mp2[x].begin();it!=mp2[x].end();it++)
	{
		if(pp==-1)
		{
			pp=it->second;
		}
		else
		{
			st.insert({pp+1,it->first-1});
			pp=it->second;
		}
	}
	return st;
}
bool check3(int pre,int post)
{
	set<pair<int,int> >st1=get_set(pre);
	set<pair<int,int> >st2=get_set(post);
	if(st1.size()==0||st2.size()==0) return true;
	auto it2=st2.begin(),it1=st1.begin();
	while(it2!=st2.end()&&it1!=st1.end())
	{
		if(it1->first>it2->second)
		{
			it2++;
		}
		else if(it1->second<it2->first)
		{
			it1++;
		}
		else
		{
			if(it2->second>it1->second)
			{
				if(it1->second-max(it2->first,it1->first)>2) return false;
				it1++;
			}
			else if(it2->second==it1->second)
			{
				if(it1->second-max(it2->first,it1->first)>2) return false;
				it1++;
			}
			else
			{
				if(it2->second-max(it2->first,it1->first)>2) return false;
				it2++;
			}
		}
	}
	return true;
}
void solve(){
	scanf("%d%d%d",&n,&m,&k);
	if(n==1||m==1)
	{
		printf("YES");
		return;
	}
	for(int i=1;i<=k;i++){
		int x1,x2,y;
		scanf("%d%d%d",&x1,&x2,&y);
		mp1[y].insert({x1,x2});
	}
	for(auto it=mp1.begin();it!=mp1.end();it++)
	{
		set<pair<int,int> > st=it->second,pil;
		auto pp=st.begin();
		int beg=(*pp).first,end=(*pp).second;
		for(auto seg:st)
		{
			if(seg.first==beg) continue;
			if(seg.first==end+1)
			{
				end=seg.second;
			}
			else
			{
				pil.insert({beg,end});
				beg=seg.first,end=seg.second;
			}
		}
		pil.insert({beg,end});
		mp2[it->first]=pil;
	}
	mp2[0].insert({1,n});
	mp2[m+1].insert({1,n});
	for(auto it=mp2.begin();it!=mp2.end();it++)
	{
		if(it->first==0)
		{
			pre=0;
			continue;
		}
		int x=it->first;
		cout<<pre<<" "<<x<<endl;
		if(x-pre>2)
		{
			flag=0;
			break;
		}
		else if(x-pre==2)
		{
			if(!tt)
			{
				if(check1(pre)&&check1(x)) tt++;
				else
				{
					flag=0;
					break;
				}
			}
			else
			{
				if(check2(pre))
				{
					;
				}
				else
				{
					flag=0;
					break;
				}
			}
		}
		else
		{
			if(pre!=0)
			{
				if(!check3(pre,x))
				{
					flag=0;
					break;
				}
			}
		}
		cout<<pre<<" "<<x<<endl;
		pre=x;
	}
	if(!flag) puts("NO");
	else puts("YES");
}
signed main(){
	int t=1;
	while(t--) solve();
	return 0;
}

/*
5 5 3
2 4 2
1 4 3
2 4 4
*/