#include <iostream>
#include <stack>
using namespace std;
stack<int> st;
int f[26],ans;
bool flag=true;
string s;
struct node
{
	int pos;
	char c;
}w[100010];
int main ()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(')
		st.push(i);
		else if(s[i]==')')
		{
			int l=st.top();
			st.pop();
			for(ans;ans>=1;ans--)
			{
				if(w[ans].pos>l)
				{
					f[w[ans].c-'a']--;
				}
				else
				break;
			}
		}
		else
		{
			if(f[s[i]-'a'])
			{
				flag=false;
				break;
			}
			else
			{
				w[++ans].pos=i;
				w[ans].c=s[i];
				f[s[i]-'a']++;
			}
		}
	}
	if(flag)
	cout<<"Yes";
	else
	cout<<"No";
	return 0;
}