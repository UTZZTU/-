#include <bits/stdc++.h>
using namespace std;
int ans,f[110];
int main ()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	for(int i=a;i<=b;i++)
	f[i]=1;
	for(int i=c;i<=d;i++)
	f[i]=1;
	for(int i=0;i<=100;i++)
	{
		if(f[i])
		{
			int j=i+1;
			while(f[j])
			{
				j++;
			}
			ans+=j-1-i;
			i=j;
		}
	}
	cout<<ans;
	return 0;
}