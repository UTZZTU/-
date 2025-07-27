#include <bits/stdc++.h>
using namespace std;
deque<char> q;
int n,flag;
string s;
int main ()
{
	scanf("%d",&n);
	getchar();
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(!i)
		{
			q.push_back(s[i]);
		}
		else
		{
			if(q.size()&&q.back()==s[i]) q.pop_back();
			else q.push_back(s[i]);
		}
	}
	while(q.size()>=2&&q.front()==q.back())
	{
		q.pop_front();
		q.pop_back();
	}
	cout<<n-q.size()<<endl;
	return 0;
}