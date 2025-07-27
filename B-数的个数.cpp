#include <bits/stdc++.h>
using namespace std;
int n,m;
int main ()
{
	while(cin>>n)
	{
		map<int,int> mp;
		if(n==0)
		break;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&m);
			mp[m]++;
		}
		cout<<mp.size()<<endl;
	}
	return 0;
}