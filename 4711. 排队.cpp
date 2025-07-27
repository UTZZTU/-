#include <bits/stdc++.h>
using namespace std;
struct people
{
	string name,prename;
	int level,num;
}s[110];
int n;
bool cmp(people a,people b)
{
	if(a.level==b.level)
	return a.num<b.num;
	else
	return a.level<b.level;
}
int main ()
{
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++)
	{
		s[i].num=i;
		cin>>s[i].name>>s[i].prename;
		if(s[i].prename=="rat")
		s[i].level=1;
		else if(s[i].prename=="woman"||s[i].prename=="child")
		s[i].level=2;
		else if(s[i].prename=="man")
		s[i].level=3;
		else
		s[i].level=4;
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		cout<<s[i].name<<endl;
	}
	return 0;
}