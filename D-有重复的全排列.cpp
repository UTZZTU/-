#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
int n,ans;
string u;
void cmp(string list,int k,int m)
{
	int i,j;
	if(k==m)
	{
		if(!mp.count(list))
		{
			cout<<list<<endl;
			mp[list]++;
			ans++;
		}
		return;
	}
	for(j=k;j<=m;j++)
	{
			swap(list[k],list[j]);
		    cmp(list,k+1,m);
		    swap(list[k],list[j]);
	}
}
int main ()
{
	scanf("%d",&n);
	getchar();
	getline(cin,u);
	cmp(u,0,n-1);
	printf("%d",ans);
	return 0;
}