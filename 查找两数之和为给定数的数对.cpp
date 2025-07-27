#include <bits/stdc++.h>
using namespace std;
int n,f[1010],x,t[1010],tt[1010],res;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		t[f[i]]=1;
	}
	cin>>x;
	for(int i=1;i<=n&&f[i]<=x;i++)
	{
		if(t[x-f[i]]&&!tt[x-f[i]])
		{
			cout<<f[i]<<","<<x-f[i]<<endl;
			tt[f[i]]=tt[x-f[i]]=1;
			res++;
		}
	}
	if(!res) cout<<"no";
	return 0;
}