#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,x,y;
ll ans;
int main ()
{
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		scanf("%d %d %d",&n,&x,&y);
		ans=n*(n+1)/2;
		cout<<"Case #"<<i<<": ";
		if(ans%(x+y)!=0)
		cout<<"IMPOSSIBLE"<<endl;
		else
		{
			cout<<"POSSIBLE"<<endl;
			vector<int> vec;
			ans=ans/(x+y)*x;
			for(int j=n;ans;j--)
			{
				if(ans>=j)
				{
					vec.push_back(j);
					ans-=j;
				}
			}
			cout<<vec.size()<<endl;
			for(auto it=vec.begin();it!=vec.end();it++)
			{
				if(it!=vec.begin())
				cout<<" ";
				cout<<*it;
			}
			cout<<endl;
		}
	}
	return 0;
}