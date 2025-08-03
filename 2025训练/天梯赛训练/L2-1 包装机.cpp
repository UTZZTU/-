#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}());
int n,m,s,op;
string p[110],str;
queue<char> q[110]; 
stack<char> st;
void solve()
{
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>p[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			q[i].push(p[i][j]);
		}
	}
	while(cin>>op)
	{
		if(op==-1) break;
		if(op==0)
		{
			if(!st.empty())
			{
				str+=st.top();
				st.pop();
			}
		}
		else
		{
			if(!q[op].empty())
			{
				if(st.size()==s)
				{
					str+=st.top();
					st.pop();
					st.push(q[op].front());
					q[op].pop();
				}
				else
				{
					st.push(q[op].front());
					q[op].pop();
				}
			}
		}
	}
	cout<<str;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}