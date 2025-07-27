#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main ()
{
	while(cin>>n>>m)
	{
		priority_queue<int> q;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&k);
			q.push(-k);
			if(q.size()>m)
			q.pop();
		}
		vector<int> vec;
		while(!q.empty())
		{
			k=q.top();
			vec.push_back(-k);
			q.pop();
		}
		for(int i=vec.size()-1;i>=0;i--)
		{
			if(i!=vec.size()-1)
			cout<<" ";
			cout<<vec[i];
		}
		cout<<endl;
	}
	return 0;
}