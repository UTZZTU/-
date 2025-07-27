#include <bits/stdc++.h>
using namespace std;
int n;
string s,u;
string zh()
{
	string v;
	for(int i=0;i<u.size();i++)
	{
		if(u[i]>='0'&&u[i]<='9') v+=u[i];
		else if(u[i]>='A'&&u[i]<='Z')
		{
			v+=('A'+(u[i]-'A'+1)%26);
		}
		else
		{
			v+=('a'+((u[i]-'a'-1)%26+26)%26);
		}
	}
	u=v;
	v.clear();
	for(int i=0;i<u.size();i++)
	{
		if(u[i]>='A'&&u[i]<='Z')
		{
			int j=i+1;
			while(j<u.size()&&u[j]>='A'&&u[j]<='Z')
			{
				j++;
			}
			if(j-i>=3)
			{
				for(int k=i;k<j;k++)
				{
					v+=u[k]+32;
				}
			}
			else
			{
				for(int k=i;k<j;k++)
				{
					v+=u[k];
				}
			}
			i=j-1;
		}
		else if(u[i]>='a'&&u[i]<='z')
		{
			int j=i+1;
			while(j<u.size()&&u[j]>='a'&&u[j]<='z')
			{
				j++;
			}
			if(j-i>=3)
			{
				for(int k=i;k<j;k++)
				{
					v+=u[k]-32;
				}
			}
			else
			{
				for(int k=i;k<j;k++)
				{
					v+=u[k];
				}
			}
			i=j-1;
		}
		else
		{
			v+=u[i];
		}
	}
	return v;
}
int main ()
{
	cin>>n>>s;
	if(s=="yourname")
	s="wangwenbo";
	cout<<s<<endl;
	u=s;
	for(int i=1;i<=n;i++)
	u=zh();
	cout<<u;
	return 0;
}