#include <bits/stdc++.h>
using namespace std;
int t,maxx;
string a,b,s;
bool judge(int x)
{
	int numa=0,numb=0,nums=0,pos=1;
	for(int i=a.size()-1;i>=0;i--)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			numa+=pos*(a[i]-'0');
			
		}
		else
		{
			numa+=pos*(10+a[i]-'A');
		}
		pos*=x;
	}
	pos=1;
	for(int i=b.size()-1;i>=0;i--)
	{
		if(b[i]>='0'&&b[i]<='9')
		{
			numb+=pos*(b[i]-'0');
			
		}
		else
		{
			numb+=pos*(10+b[i]-'A');
		}
		pos*=x;
	}
	pos=1;
	for(int i=s.size()-1;i>=0;i--)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			nums+=pos*(s[i]-'0');
			
		}
		else
		{
			nums+=pos*(10+s[i]-'A');
		}
		pos*=x;
	}
	return numa+numb==nums;
}
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>s;
		maxx=2;
		for(int i=0;i<a.size();i++)
		{
			if(a[i]>='0'&&a[i]<='9')
			maxx=max(maxx,a[i]-'0'+1);
			else
			maxx=max(maxx,a[i]-'A'+11);
		}
		for(int i=0;i<b.size();i++)
		{
			if(b[i]>='0'&&b[i]<='9')
			maxx=max(maxx,b[i]-'0'+1);
			else
			maxx=max(maxx,b[i]-'A'+11);
		}
		for(int i=0;i<s.size();i++)
		{
			if(s[i]>='0'&&s[i]<='9')
			maxx=max(maxx,s[i]-'0'+1);
			else
			maxx=max(maxx,s[i]-'A'+11);
		}
		for(maxx;maxx<=16;maxx++)
		{
			if(judge(maxx))
			{
				printf("%d\n",maxx);
				break;
			}
		}
	}
	return 0;
}