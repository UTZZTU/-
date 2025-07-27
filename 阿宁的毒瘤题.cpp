#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll qzh[200010],hzh[200010],res1,res2,pos=-1,maxx,qz[200010],hz[200010],gx;
int main ()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='u')
		{
			res1++;
			qz[i+1]=qz[i];
		}
		else if(s[i]=='d')
		{
			res2++;
			qz[i+1]=qz[i]+res1;
		}
	    else
	    {
	    	qz[i+1]=qz[i];
		}
		qzh[i+1]=res1;
	}
	res1=res2=0;
	for(int i=s.size()-1;i>=0;i--)
	{
		if(s[i]=='u')
		{
			res1++;
			hz[i+1]=hz[i+2];
		}
		else if(s[i]=='d')
		{
			res2++;
			hz[i+1]=hz[i+2]+res1;
		}
        else
        {
        	hz[i+1]=hz[i+2];
		}
		hzh[i+1]=res1;
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='u')
		{
			gx=qz[i+1]+hz[i+1];
			if(gx>maxx)
			{
				maxx=gx;
				pos=i;
			}
		}
		else if(s[i]=='d')
		{
			gx=qzh[i+1]*hzh[i+1];
			if(gx>maxx)
			{
				maxx=gx;
				pos=i;
			}
		}
	}
	if(pos==-1)
	cout<<s;
	else
	{
		s[pos]='z';
		cout<<s;
	}
	return 0;
}