#include <bits/stdc++.h>
using namespace std;
string u,v;
int f[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int get_day(int a,int b,int c)
{
	int res=0;
	for(int i=1;i<a;i++)
	{
		if(i%4==0&&i%100!=0||i%400==0)
		res+=366;
		else res+=365;
	}
	if(a%4==0&&a%100!=0||a%400==0)
		f[2]=29;
	else f[2]=28;
	for(int i=1;i<b;i++)
	{
		res+=f[i];
	}
	res+=c;
	return res;
}
int solve()
{
	int year1=0,year2=0,mon1=0,mon2=0,day1=0,day2=0;
	for(int i=0;i<u.size();i++)
	{
		if(i<4)
		{
			year1=year1*10+u[i]-'0';
		}
		else if(i<6)
		{
			mon1=mon1*10+u[i]-'0';
		}
		else
		{
			day1=day1*10+u[i]-'0';
		}
	}
	for(int i=0;i<v.size();i++)
	{
		if(i<4)
		{
			year2=year2*10+v[i]-'0';
		}
		else if(i<6)
		{
			mon2=mon2*10+v[i]-'0';
		}
		else
		{
			day2=day2*10+v[i]-'0';
		}
	}
	int tt1=get_day(year1,mon1,day1),tt2=get_day(year2,mon2,day2);
	return tt2-tt1+1;
}
int main ()
{
	while(cin>>u)
	{
		cin>>v;
		if(u>v) swap(u,v);
		cout<<solve()<<endl;
	}
	return 0;
}