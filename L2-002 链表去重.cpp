#include <bits/stdc++.h>
using namespace std;
int da[100100],ne[100100],ks,n;
vector<int> yl;
vector<int> tc;
set<int> p;
int main ()
{
	cin>>ks>>n;
	for(int i=1,k;i<=n;i++)
	{
		scanf("%d",&k);
		scanf("%d %d",&da[k],&ne[k]);
	}
	for(int i=ks;~i;i=ne[i])
	{
		if(p.find(abs(da[i]))!=p.end())
		{
			tc.push_back(i);
		}
		else
		{
			yl.push_back(i);
			p.insert(abs(da[i]));
		}
	}
	for(int i=0;i<yl.size();i++)
	{
		printf("%05d %d ",yl[i],da[yl[i]]);
		if(i==yl.size()-1)
		cout<<-1<<endl;
		else
		printf("%05d\n",yl[i+1]);
	}
	for(int i=0;i<tc.size();i++)
	{
		printf("%05d %d ",tc[i],da[tc[i]]);
		if(i==tc.size()-1)
		cout<<-1;
		else
		printf("%05d\n",tc[i+1]);
	}
	return 0;
}