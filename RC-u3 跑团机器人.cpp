#include <bits/stdc++.h>
using namespace std;
string u;
int tot;
map<int,int> mp;
long long sum1,sum2;
int zszd,zszx,fszd,fszx;
int main ()
{
	getline(cin,u);
	int k=1,gs=0,num=0,pd=0;
	for(int i=0;i<u.size();i++)
	{   
	   if(i==0)
	   {
	   	if(u[0]=='-')
	   	{
	   		k=-1;
	   		i++;
		   }
		   else
		   k=1;
		   gs=0;
		   while(u[i]>='0'&&u[i]<='9')
		   {
		   	gs=gs*10+u[i]-'0';
		   	i++;
		   }
		   if(gs==0)
		   gs=1;
		   if(u[i]=='d')
		   {
		   	i++;
		   	num=0;
		   	while(u[i]>='0'&&u[i]<='9')
		   {
		   	num=num*10+u[i]-'0';
		   	i++;
		   }
		   i--;
		   if(k==1)
		   {
		   	zszd+=gs*num;
		   zszx+=gs;
		   }
		   else if(k==-1)
		   {
		   	fszd+=gs*num;
		   fszx+=gs;
		   }
		   if(mp.find(num)==mp.end())
		   mp[num]=gs;
		   else
		   mp[num]+=gs;
		   }
		   else if(u[i]=='+'||u[i]=='-')
		   {
		   	i--;
		   	tot+=k*gs;
		   }
	   }
	   else if(u[i]=='+')
	   {
	   	i++;
	   	k=1;
	   	gs=0;
		   while(u[i]>='0'&&u[i]<='9')
		   {
		   	gs=gs*10+u[i]-'0';
		   	i++;
		   }
		   if(gs==0)
		   gs=1;
		   if(u[i]=='d')
		   {
		   	i++;
		   	num=0;
		   	while(u[i]>='0'&&u[i]<='9')
		   {
		   	num=num*10+u[i]-'0';
		   	i++;
		   }
		   i--;
		   zszd+=gs*num;
		   zszx+=gs;
		   if(mp.find(num)==mp.end())
		   mp[num]=gs;
		   else
		   mp[num]+=gs;
		   }
		   else if(u[i]=='+'||u[i]=='-')
		   {
		   	i--;
		   	tot+=k*gs;
		   }
	   }else if(u[i]=='-')
	   {
	   	i++;
	   	k=-1;
	   	gs=0;
		   while(u[i]>='0'&&u[i]<='9')
		   {
		   	gs=gs*10+u[i]-'0';
		   	i++;
		   }
		   if(gs==0)
		   gs=1;
		   if(u[i]=='d')
		   {
		   	i++;
		   	num=0;
		   	while(u[i]>='0'&&u[i]<='9')
		   {
		   	num=num*10+u[i]-'0';
		   	i++;
		   }
		   i--;
		   fszd+=gs*num;
		   fszx+=gs;
		   if(mp.find(num)==mp.end())
		   mp[num]=gs;
		   else
		   mp[num]+=gs;
		   }
		   else if(u[i]=='+'||u[i]=='-')
		   {
		   	i--;
		   	tot+=k*gs;
		   }
	   }
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	sum1+=zszx+tot-fszd;sum2+=zszd+tot-fszx;
	cout<<sum1<<" "<<sum2;
	return 0;
}