#include <bits/stdc++.h>
using namespace std;
int t,flag;
string s,a,b,c;
bool judge()
{
	int res1=0,res2=0,pre_first_a=-1,pre_first_b=-1,post_first_a=-1,post_first_b=-1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='a')
		{
			res1++;
			if(pre_first_a==-1&&i!=0)
			pre_first_a=i;
		}
		else
		{
			res2++;
			if(pre_first_b==-1&&i!=0)
			pre_first_b=i;
		}
	}
	for(int j=s.size()-1;j>=0;j--)
	{
		if(s[j]=='a')
		{
			if(post_first_a==-1)
			post_first_a=j;
		}
		else
		{
			if(post_first_b==-1)
			post_first_b=j;
		}
	}
	if(res1==s.size()||res2==s.size())
	{
		a=c=s[0];
		b=s.substr(1,s.size()-2);
		return true;
	}
	if(s[0]=='a')
	{
		if(pre_first_a>0&&pre_first_a<s.size()-1)
		{
			a=s.substr(0,pre_first_a);
			b=s.substr(pre_first_a,1);
			c=s.substr(pre_first_a+1,s.size()-(pre_first_a+1));
			return true;
		}
		if(pre_first_b<post_first_a)
		{
			a=s.substr(0,pre_first_b);
			b=s.substr(pre_first_b,post_first_a-pre_first_b);
			c=s.substr(post_first_a,s.size()-post_first_a);
			return true;
		}
		if(pre_first_b<post_first_b)
		{
			a=s.substr(0,pre_first_b);
			b=s.substr(pre_first_b,post_first_b-pre_first_b);
			c=s.substr(post_first_b,s.size()-post_first_b);
			return true;
		}
	}
	else if(s[0]=='b')
	{
	    if(pre_first_a>0&&pre_first_a<s.size()-1)
		{
			a=s.substr(0,pre_first_a);
			b=s.substr(pre_first_a,1);
			c=s.substr(pre_first_a+1,s.size()-(pre_first_a+1));
			return true;
		}
		if(pre_first_b<post_first_b)
		{
			a=s.substr(0,pre_first_b);
			b=s.substr(pre_first_b,1);
			c=s.substr(pre_first_b+1,s.size()-(pre_first_b+1));
			return true;
		}
		if(pre_first_b<post_first_a)
		{
			a=s.substr(0,1);
			b=s.substr(1,post_first_a-1);
			c=s.substr(post_first_a,s.size()-post_first_a);
			return true;
		}
		
	}
	return false;
}
int main ()
{
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		flag=0;
		cin>>s;
		if(judge())
		flag=1;
		if(flag)
		cout<<a<<" "<<b<<" "<<c<<endl;
		else
		printf(":(\n");
	}
	return 0;
}