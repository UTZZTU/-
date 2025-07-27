#include <bits/stdc++.h>
using namespace std;
string u;
int n,m,res1,res2,res;
int main ()
{
	cin>>n>>m;
	res1=m;
	res2=n-m;
	while(res1)
	{
		u+="1";
		res1--;
		if(res2>=2)
		{
			res2-=2;
			u+="00";
		}
		else if(res2==1)
		{
			res2-=1;
			u+="0";
		}
		else
		{
			if(res1)
			{
				res1--;
				u+="1";
			}
			else
			break;
		}
	}
	for(int i=1;i<=res2;i++)
	{
		u+="0";
	}
	if(u.size()<3)
	{
		cout<<0;
	}
	else
	{
		res1=0,res2=0;
		int i=0;
		for(i=0;i<3;i++)
		{
			if(u[i]=='0')
			res2++;
			else
			res1++;
		}
		if(res1>res2)
		res++;
		for(i;i<u.size();i++)
		{
			if(u[i]=='0')
			res2++;
			else
			res1++;
			if(u[i-3]=='0')
			res2--;
			else
			res1--;
			if(res1>res2)
		    res++;
		}
		cout<<res;
	}
	return 0;
}