#include <iostream>
#include <vector>
using namespace std;
vector<int> p;
int a[1010],f=0;
void dfs(int l,int r)
{
	int root_date=a[l];
	int i=l+1,j=r;
	if(!f)
	{
		while(i<=r&&a[i]<root_date)
		i++;
		while(j>l&&a[j]>=root_date)
		j--;
	}
	else
	{
		while(i<=r&&a[i]>=root_date)
		i++;
		while(j>l&&a[j]<root_date)
		j--;
	}
	if(i-j!=1)
	return;
	dfs(l+1,j);
	dfs(i,r);
	p.push_back(root_date);
}
int main ()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	dfs(0,n-1);
	if(p.size()!=n)
	{
		p.clear();
		f=1;
		dfs(0,n-1);
	}
	if(p.size()!=n)
	{
		printf("NO");
	}
	else
	{
		printf("YES\n");
		for(auto it=p.begin();it!=p.end();it++)
		{
			if(it!=p.begin())
			printf(" ");
			cout<<*it;
		}
	}
	return 0;
}