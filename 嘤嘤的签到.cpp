#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll res,n,res1,res2;
string s;
deque<int> q;
int main ()
{
	cin>>n;
	getchar();
	cin>>s;
	for(int i=0;i<n;i++)
	{
		q.push_back(s[i]-'0');
		if(s[i]-'0'==1)
		{
			res1++;
		}
		else if(s[i]-'0'==4)
		{
			res2++;
		}
		while(res1&&res2)
		{
			if(q.front()==1) res1--;
			else if(q.front()==4) res2--;
			q.pop_front();
		}
		res+=q.size();
	}
	cout<<res;
	return 0;
}