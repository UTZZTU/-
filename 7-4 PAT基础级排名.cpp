#include <bits/stdc++.h>
using namespace std;
int level[6]={0,30,50,60,80,100};
int rs[6];
struct student
{
	string card;
	int dj;
	int grade;
	int zf;
	int pm;
	int xmdrs;
}s[1010];
bool cmp(student a,student b)
{
	if(a.grade!=b.grade)
	return a.grade>b.grade;
	else
	return a.card<b.card;
}
int main ()
{
	int n,l;
	cin>>n>>l;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].card>>s[i].grade;
	}
	sort(s+1,s+1+n,cmp);
	int num=n,zddj,rs,js=0,fs;
	for(int i=1;i<=n;i++)
	{
		int u=lower_bound(level+1,level+5,s[i].grade)-level;
		if(s[i].grade==0)
		s[i].dj=0;
		else
		s[i].dj=u;
		if(i==1)
		{
			fs=s[i].grade;
			zddj=s[i].dj;
			rs=1;
			s[i].zf=level[u];
			s[i].pm=rs;
			s[i].xmdrs=num;
			js++;
		}
		else
		{
			
			if(u==zddj)
			{
				rs++;
			    js++;
				s[i].zf=level[u];
				if(s[i].grade==fs)
				s[i].pm=s[i-1].pm;
				else
				{
					s[i].pm=rs;
					fs=s[i].grade;
				}
				s[i].xmdrs=num;
			}
			else
			{
				zddj=u;
				rs=1;
				num-=js;
				js=1;
				s[i].zf=level[u];
				s[i].pm=rs;
				s[i].xmdrs=num;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i].grade==0)
		cout<<s[i].card<<endl;
		else
		cout<<s[i].card<<" "<<s[i].dj<<" "<<s[i].grade<<"/"<<s[i].zf<<" "<<s[i].pm<<"/"<<s[i].xmdrs<<endl;
	}
	return 0;
}