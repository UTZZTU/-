#include <bits/stdc++.h>
using namespace std;
int m,n,judge,k;
string a="push",b="pop",u;
int main ()
{
	cin>>m;
	while(m--)
	{
		judge=0;
		cin>>n;
		getchar();
		queue<int> q;
		stack<int> st;
		for(int i=1;i<=n;i++)
		{
			cin>>u;
			if(u==a)
			{
				cin>>k;
				q.push(k);
				st.push(k);
			}
			else if(u==b)
			{
				if(q.empty()||st.empty())
				{
					judge=1;
				}
				else
				{
					q.pop();
					st.pop();
				}
			}
		}
		if(judge)
		cout<<"error"<<endl<<"error"<<endl;
		else
		{
			vector<int> p;
		while(!q.empty())
		{
          p.push_back(q.front());
           q.pop();
		}
		for(int i=0;i<p.size();i++)
		{
			if(i!=0)
			cout<<" ";
			cout<<p[i];
		}
		cout<<endl;
		vector<int> vec;
		while(!st.empty())
		{
			vec.push_back(st.top());
			st.pop();
		}
		reverse(vec.begin(),vec.end());
		for(int i=0;i<vec.size();i++)
		{
			if(i!=0)
			cout<<" ";
			cout<<vec[i];
		}
		cout<<endl;
		}
	}
	return 0;
}