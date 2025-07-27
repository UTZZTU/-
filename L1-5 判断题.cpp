#include <bits/stdc++.h>
using namespace std;
int n,m,res,reall[110],k,judge[110];
int main ()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	cin>>reall[i];
	for(int i=1;i<=m;i++)
	cin>>judge[i];
	for(int i=1;i<=n;i++)
	{
		res=0;
		for(int j=1;j<=m;j++)
		{
			cin>>k;
			if(k==judge[j]) res+=reall[j];
		}
		cout<<res<<endl;
	}
	return 0;
}