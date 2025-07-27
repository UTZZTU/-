#include <bits/stdc++.h>
using namespace std;
int n,m,f[110],k,w,bg;
vector<int> vec[1000010];
int main ()
{
	memset(f,1,sizeof f);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		while(k--)
		{
			cin>>w;
			vec[i].push_back(w);
		}
	}
	bg=1;
	while(m--)
	{
		cin>>k>>w;
		if(k==0)
		{
			bg=vec[bg][w-1];
		}else if(k==1)
		{
			f[w]=bg;
			cout<<bg<<endl;
		}else if(k==2)
		{
			bg=f[w];
		}
	}
	cout<<bg;
	return 0;
}