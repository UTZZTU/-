#include <bits/stdc++.h>
using namespace std;
struct node
{
	string address,next;
	int data;
}s1[100010],s2[100010];
int k1,k2,m1,m2;
map<string,pair<int,string>> mp;
int main ()
{
	string a,b;
	int n;
	cin>>a>>b>>n;
	getchar();
	for(int i=1;i<=n;i++)
	{
		string u;
		pair<int,string> o;
		cin>>u>>o.first>>o.second;
		mp[u]=o;
	}
	while(a[0]!='-')
	{
		pair<int,string> o;
		o=mp[a];
		s1[++k1].address=a;
		s1[k1].data=o.first;
		s1[k1].next=o.second;
		a=o.second;
	}
	while(b[0]!='-')
	{
		pair<int,string> o;
		o=mp[b];
		s2[++k2].address=b;
		s2[k2].data=o.first;
		s2[k2].next=o.second;
		b=o.second;
	}
	if(k1>=2*k2)
	{
		m1=1;
		m2=k2;
		while(m1<=k1||m2>=1)
		{
			if(m1<=k1)
			{
				cout<<s1[m1].address<<" "<<s1[m1].data<<" "<<s1[m1].next<<endl;
				m1++;
			}
			if(m1<=k1)
			{
				cout<<s1[m1].address<<" "<<s1[m1].data<<" ";
				if(m2>=1)
				cout<<s2[m2].address<<endl;
				else
				cout<<s1[m1].next<<endl;
				m1++;
			}
			if(m2>=1)
			{
				cout<<s2[m2].address<<" "<<s2[m2].data<<" ";
				if(m1<=k1)
				cout<<s1[m1].address<<endl;
				else
				cout<<s2[m2].next;
				m2--;
			}
		}
	}
	else
	{
		m1=k1;
		m2=1;
		while(m1>=1||m2<=k2)
		{
			if(m2<=k2)
			{
				cout<<s2[m2].address<<" "<<s2[m2].data<<" "<<s2[m2].next<<endl;
				m2++;
			}
			if(m2<=k2)
			{
				cout<<s2[m2].address<<" "<<s2[m2].data<<" ";
				if(m1>=1)
				cout<<s1[m1].address<<endl;
				else
				cout<<s2[m2].next<<endl;
				m2++;
			}
			if(m1>=1)
			{
				cout<<s1[m1].address<<" "<<s1[m1].data<<" ";
				if(m2<=k2)
				cout<<s2[m2].address<<endl;
				else
				cout<<s1[m1].next;
				m1--;
			}
		}
	}
	return 0;
}