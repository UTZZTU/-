#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
struct people
{
	string name;
	int cl;
}s[10];
int k;
bool cmp(people a,people b)
{
	return a.cl>b.cl;
}
int main ()
{
	mp["Bessie"]=0;
	mp["Elsie"]=0;
	mp["Daisy"]=0;
	mp["Gertie"]=0;
	mp["Annabelle"]=0;
	mp["Maggie"]=0;
	mp["Henrietta"]=0;
	int n;
	cin>>n;
	for(int i=1,v;i<=n;i++)
	{
		string u;
		cin>>u>>v;
		mp[u]+=v;
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		s[++k].name=it->first;
		s[k].cl=it->second;
	}
	sort(s+1,s+8,cmp);
	int cl=s[7].cl,pd=0,js=0;
	string wz;
	for(int i=6;i>=1;i--)
	{
		if(s[i].cl>cl)
		{
			pd++;
			if(pd==2)
			break;
			else
			{
				cl=s[i].cl;
				js++;
				wz=s[i].name;
			}
		}
		else if(s[i].cl==cl)
		{
			if(pd==1)
			{
				js++;
			}
		}
	}
	if(js>1||cl==s[7].cl)
	cout<<"Tie";
	else
	cout<<wz;
	return 0;
}