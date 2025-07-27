#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int n,ans;
string f;
map<string,int> mp;
void fun(string list,int k,int m)
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
		    fun(list,k+1,m);
		    swap(list[k],list[j]);
	}
}
int main ()
{
	scanf("%d",&n);
	getchar();
	getline(cin,f);
	fun(f,0,n-1);
	cout<<ans;
	return 0;
}