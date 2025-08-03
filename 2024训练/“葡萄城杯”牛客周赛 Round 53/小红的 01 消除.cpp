#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
deque<char> dq;
int n,cnt;
int x,y,z;
void solve()
{
	cin>>n;
	cin>>s;
	cin>>x>>y>>z;
	for(int i=0;i<n;i++)
	{
		if(dq.size()==0)
		{
			dq.push_back(s[i]);
		}
		else if(s[i]=='1')
		{
			if(dq.back()=='0')
			{
				if(cnt>=y)
				{
					cout<<y<<endl;
					return;
				}
				dq.pop_back();
				cnt++;
			}
			else
			{
				if(x>0)
				{
					x--;
					dq.pop_back();
				}
				else
				{
					dq.push_back(s[i]);
				}
			}
		}
		else
		{
			dq.push_back(s[i]);
		}
	}
	cout<<cnt<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}