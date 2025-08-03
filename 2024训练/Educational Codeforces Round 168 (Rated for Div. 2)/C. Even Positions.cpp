#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int n;
ll res,cnt;
void solve()
{
	res=0;
	cin>>n;
	cin>>s;
	stack<int> st;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(')
		{
			st.push(i);
			cnt--;
		}
		else if(s[i]==')')
		{
			int x=st.top();
			st.pop();
			res+=i-x;
			cnt++;
		}
		else
		{
			if(cnt+1>0)
			{
				st.push(i);
				cnt--;
			}
			else
			{
				int x=st.top();
				st.pop();
				res+=i-x;
				cnt++;
			}
		}
	}
	cout<<res<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}