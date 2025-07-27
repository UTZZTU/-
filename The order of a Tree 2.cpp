#include <iostream>
#include <vector>
using namespace std;
vector<int> p;
int a[1010],f=0;
void dfs(int l,int r)
{
	int root_date=a[l];
	int i=l+1,j=r;
		while(i<=r&&a[i]<root_date)
		i++;
		while(j>l&&a[j]>=root_date)
		j--;
		if(j>=l+1)
	dfs(l+1,j);
	if(i<=r)
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
		for(auto it=p.begin();it!=p.end();it++)
		{
			if(it!=p.begin())
			printf(" ");
			cout<<*it;
		}
	return 0;
}