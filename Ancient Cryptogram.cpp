#include <bits/stdc++.h>
using namespace std;
map<char,int> mp1,mp2;
map<int,int> mp3,mp4;
string u,v;
int main ()
{
	cin>>u>>v;
	for(int i=0;i<u.size();i++)
	mp1[u[i]]++;
	for(auto it=mp1.begin();it!=mp1.end();it++)
	mp3[it->second]++;
	for(int i=0;i<v.size();i++)
	mp2[v[i]]++;
	for(auto it=mp2.begin();it!=mp2.end();it++)
	mp4[it->second]++;
	if(mp3.size()!=mp4.size())
	{
		cout<<"NO";
		return 0;
	}
	for(auto it1=mp3.begin(),it2=mp4.begin();it1!=mp3.end(),it2!=mp4.end();it1++,it2++)
	{
		if(!(it1->first==it2->first&&it1->second==it2->second))
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}