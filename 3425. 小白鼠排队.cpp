#include <bits/stdc++.h>
using namespace std;
int n;
struct mouse{
	int weight;
	string hat;
}s[110];
bool cmp(mouse a,mouse b)
{
	return a.weight>b.weight;
}
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].weight>>s[i].hat;
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		cout<<s[i].hat<<endl;
	}
	return 0;
}