#include <bits/stdc++.h>
using namespace std;
struct student
{
	int ch,ma,en,num,score;
}s[1010];
bool cmp(student a,student b)
{
	if(a.score!=b.score)
	return a.score>b.score;
	else if(a.ch!=b.ch)
	return a.ch>b.ch;
	else
	return a.num<b.num;
}
int n;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].ch>>s[i].ma>>s[i].en;
		s[i].num=i;
		s[i].score=s[i].ch+s[i].en+s[i].ma;
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=5;i++)
	cout<<s[i].num<<" "<<s[i].score<<endl;
	return 0;
}