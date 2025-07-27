#include <bits/stdc++.h>
using namespace std;
map<int,vector<int>> mp1;
set<int> st;
map<int,char> mp2;
map<int,int> mp3;
int n,k,ans1,ans2,pd;
vector<int> vec1,vec2,vec3,vec;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		mp3[k]++;
		mp1[k].push_back(i);
	}
	for(auto it=mp3.begin();it!=mp3.end();it++)
	{
		if(it->second==1)
		{
			ans1++;
			vec1.push_back(it->first);
		}
		else if(it->second>=3)
		{
			ans2++;
			vec2.push_back(it->first);
		}
		else
		vec3.push_back(it->first);
	}
	if(ans1%2==0)
	{
		cout<<"YES"<<endl;
		for(int i=0;i<vec1.size();i++)
		{
			if(i<(vec1.size()/2))
			{
				vec=mp1[vec1[i]];
				for(int j=0;j<vec.size();j++)
				mp2[vec[j]]='B';
			}
			else
			{
				vec=mp1[vec1[i]];
				for(int j=0;j<vec.size();j++)
				mp2[vec[j]]='A';
			}
		}
		for(int i=0;i<vec2.size();i++)
		{
			vec=mp1[vec2[i]];
			for(int j=0;j<vec.size();j++)
			mp2[vec[j]]='A';
		}
		for(int i=0;i<vec3.size();i++)
		{
			vec=mp1[vec3[i]];
			for(int j=0;j<vec.size();j++)
			mp2[vec[j]]='A';
		}
		for(auto it=mp2.begin();it!=mp2.end();it++)
		cout<<it->second;
	}
	else if((ans1&1)&&ans2>=1)
	{
		cout<<"YES"<<endl;
		for(int i=0;i<vec3.size();i++)
		{
			vec=mp1[vec3[i]];
			for(int j=0;j<vec.size();j++)
			mp2[vec[j]]='A';
		}
		for(int i=0;i<vec1.size();i++)
		{
			if(i<(vec1.size()/2))
			{
				vec=mp1[vec1[i]];
				for(int j=0;j<vec.size();j++)
				mp2[vec[j]]='B';
			}
			else
			{
				vec=mp1[vec1[i]];
				for(int j=0;j<vec.size();j++)
				mp2[vec[j]]='A';
			}
		}
		for(int i=0;i<vec2.size();i++)
		{
			vec=mp1[vec2[i]];
			for(int j=0;j<vec.size();j++)
			{
				if(!pd)
				{
					mp2[vec[j]]='B';
					pd=1;
				}
				else
				mp2[vec[j]]='A';
			}
		}
		for(auto it=mp2.begin();it!=mp2.end();it++)
		cout<<it->second;
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}