#include <bits/stdc++.h>
using namespace std;
int a,b,data[100010],ne[100010],n;
vector<int> s1,s2,late;
int main ()
{
	scanf("%d %d %d",&a,&b,&n);
	for(int i=1;i<=n;i++)
	{
		int u;
		scanf("%d",&u);
		scanf("%d %d",&data[u],&ne[u]);
	}
	for(int i=a;~i;i=ne[i])
	s1.push_back(i);
	for(int i=b;~i;i=ne[i])
	s2.push_back(i);
	if(s1.size()<s2.size())
	swap(s1,s2);
	reverse(s2.begin(),s2.end());
	for(int i=0,j=0;i<s1.size();)
	{
		late.push_back(s1[i++]);
		if(i%2==0&&j<s2.size())
		late.push_back(s2[j++]);
	}
	for(int i=0;i<late.size();i++)
	{
		printf("%05d %d ",late[i],data[late[i]]);
		if(i==late.size()-1)
		printf("-1");
		else
		printf("%05d\n",late[i+1]);
	}
	return 0;
}