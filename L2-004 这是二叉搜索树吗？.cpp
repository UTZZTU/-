#include <bits/stdc++.h>
using namespace std;
int f,a[1010];
vector<int> p;
void fun(int l,int r)
{
	int root_date=a[l];
	int x=l+1,y=r;
	if(!f)
	{
		while(a[x]<root_date&&x<=r)
		x++;
		while(a[y]>=root_date&&y>l)
		y--;
	}
	else
	{
		while(a[x]>=root_date&&x<=r)
		x++;
		while(a[y]<root_date&&y>l)
		y--;
	}
	if(x-y!=1)
	return;
	fun(l+1,y);
	fun(x,r);
	p.push_back(a[l]);
}
int main ()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	fun(0,n-1);
	if(p.size()!=n)
	{
		p.clear();
		f=1;
		fun(0,n-1);
	}
	if(p.size()!=n)
	cout<<"NO";
	else
	{
		cout<<"YES"<<endl;
		for(auto it=p.begin();it!=p.end();it++)
		{
			if(it!=p.begin())
			cout<<" ";
			cout<<*it;
		}
	}
	return 0;
}