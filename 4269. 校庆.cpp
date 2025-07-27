#include <bits/stdc++.h>
using namespace std;
int n,m,tot,k1=1,k2=1;
string u;
map<string,int> mp;
struct people
{
	string a;
	int year,month,day;
}s1[100010],s2[100010];
bool cmp(people a,people b)
{
	if(a.year!=b.year)
	return a.year<b.year;
	else if(a.month!=b.month)
	return a.month<b.month;
	else
	return a.day<b.day;
}
int main ()
{
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++)
	{
		cin>>u;
		mp[u]=1;
	}
	cin>>m;
	getchar();
	for(int i=1;i<=m;i++)
	{
		cin>>u;
		tot+=mp[u];
	    if(mp[u])
	    {
	    	s1[k1].a=u;
	    	int v=0;
	    	for(int j=6;j<=9;j++)
	    	v=v*10+u[j]-'0';
	    	s1[k1].year=v;
	    	v=0;
	    	for(int j=10;j<=11;j++)
	    	v=v*10+u[j]-'0';
	    	s1[k1].month=v;
	    	v=0;
	    	for(int j=12;j<=13;j++)
	    	v=v*10+u[j]-'0';
	    	s1[k1].day=v;
	    	k1++;
		}
		else
		{
			s2[k2].a=u;
	    	int v=0;
	    	for(int j=6;j<=9;j++)
	    	v=v*10+u[j]-'0';
	    	s2[k2].year=v;
	    	v=0;
	    	for(int j=10;j<=11;j++)
	    	v=v*10+u[j]-'0';
	    	s2[k2].month=v;
	    	v=0;
	    	for(int j=12;j<=13;j++)
	    	v=v*10+u[j]-'0';
	    	s2[k2].day=v;
	    	k2++;
		}
	}
	cout<<tot<<endl;
	sort(s1+1,s1+k1,cmp);
	sort(s2+1,s2+k2,cmp);
	if(k1!=1)
	cout<<s1[1].a;
	else
	cout<<s2[1].a;
	return 0;
}