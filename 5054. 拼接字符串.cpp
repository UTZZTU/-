#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,u;
map<string,bool> mp;
int n;
string new_str(string s)
{
	string v;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='a'&&s[i]<='z')
		{
			v+=s[i];
		}
		else if(s[i]>='A'&&s[i]<='Z')
		{
			v+=(s[i]+32);
		}
	}
	return v;
}
int main ()
{
	cin>>s1>>s2>>s3;
	s1=new_str(s1);
	s2=new_str(s2);
	s3=new_str(s3);
	mp[s1+s2+s3]=true;
	mp[s1+s3+s2]=true;
	mp[s2+s1+s3]=true;
	mp[s2+s3+s1]=true;
	mp[s3+s2+s1]=true;
	mp[s3+s1+s2]=true;
	cin>>n;
	getchar();
	while(n--)
	{
		cin>>u;
		u=new_str(u);
		if(mp[u]) cout<<"ACC"<<endl;
		else cout<<"WA"<<endl;
	}
	return 0;
}