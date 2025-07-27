#include <iostream>
using namespace std;
int pre[110];
int main ()
{
	int n,m;
	while(cin>>n>>m)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		pre[i]=i;
		for(int i=1;i<=m;i++)
		{
			int q,h;
			cin>>q>>h;
			pre[h]=q;
		}
		for(int i=1;i<=n;i++)
		{
			if(pre[i]==i)
			sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
}