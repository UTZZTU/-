#include <bits/stdc++.h>
using namespace std;
int n;
struct node
{
	char s;
	int pos;
};
string u;
int main ()
{
	while(cin>>n)
	{
		stack<node> st;
		getchar();
		cin>>u;
		vector<int> vec;
		for(int i=0;i<u.size();i++)
		{
			if(u[i]=='1')
			st.push({u[i],i+1});
			else
			{
				vec.push_back(st.top().pos);
				st.pop();
			}
		}
		for(int i=0;i<vec.size();i++)
		{
			if(i!=0)
			cout<<" ";
			cout<<vec[i];
		}
		cout<<endl;
	}
	return 0;
}