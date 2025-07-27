#include <bits/stdc++.h>
using namespace std;
struct node
{
	int num,pos;
}s[11];
bool cmp(node x,node y)
{
	if(x.pos!=y.pos)
	return x.pos>y.pos;
	else
	{
		if(x.pos==1)
		{
			return x.num>y.num;
		}
		else
		{
			return x.num<y.num;
		}
	}
}
int main ()
{
	for(int i=1;i<=10;i++)
	{
		cin>>s[i].num;
		s[i].pos=s[i].num%2;
	}
	sort(s+1,s+1+10,cmp);
	for(int i=1;i<=10;i++)
	cout<<s[i].num<<" ";
	return 0;
}