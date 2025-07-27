#include<iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
struct people
{
	string name;
	string sfz;
	int stqk;
	int xs,fz;
	int l;
	int sfzq;
}s[1010],y[1010];
bool cmp(people a,people b)
{
	if(a.xs!=b.xs)
	return a.xs<b.xs;
	else
	return a.fz<b.fz;
}
int main ()
{
	int d,p,ts,zpx=1;
	map<string,int> mp;
	cin>>d>>p;
	for(ts=1;ts<=d;ts++)
	{
		int t,si,i;
		cin>>t>>si;
		getchar();
		for(i=1;i<=t;i++)
		{
			int zd=0;
			cin>>s[i].name>>s[i].sfz>>s[i].stqk;
			scanf("%d:%d",&s[i].xs,&s[i].fz);
			s[i].l=s[i].sfz.length();
			for(int j=0;s[i].sfz[j]!='\0';j++)
			{
				if(s[i].sfz[j]<'0'||s[i].sfz[j]>'9')
				{
					zd=1;
					break;
				}
			}
			if(zd==1)
			s[i].sfzq=0;
			else
			s[i].sfzq=1;
			if(s[i].stqk==1&&s[i].l==18&&s[i].sfzq==1)
			{
				int zd=0;
				for(int j=1;j<zpx;j++)
				{
					if(y[j].sfz==s[i].sfz)
					{
						zd=1;
						break;
					}
				}
				if(zd==0)
				{
					y[zpx].name=s[i].name;
				y[zpx].sfz=s[i].sfz;
				zpx++;
				}
			}
		}
		sort(s+1,s+1+t,cmp);
		if(ts==1)
		{
			for(i=1;i<=t;i++)
			{
				if(s[i].l==18&&s[i].sfzq==1)
				{
					cout<<s[i].name<<" "<<s[i].sfz<<endl;
					mp[s[i].sfz]=ts;
					si--;
					if(si<=0)
					break;
				}
			}
		}
		else
		{
			for(i=1;i<=t;i++)
			{
				if(s[i].l==18&&s[i].sfzq==1)
				{
					map<string,int>::iterator it;
					it=mp.find(s[i].sfz);
					if(it==mp.end()||ts-mp[s[i].sfz]>=p+1)
					{
						cout<<s[i].name<<" "<<s[i].sfz<<endl;
					mp[s[i].sfz]=ts;
					si--;
					if(si<=0)
					break;
					}
				}
			}
		}
	}
	for(int i=1;i<zpx;i++)
	cout<<y[i].name<<" "<<y[i].sfz<<endl;
	return 0;
}