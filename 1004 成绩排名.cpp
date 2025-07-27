#include <bits/stdc++.h>
using namespace std;
struct student
{
	string name,num;
	int grade;
}s[1010];
bool cmp(student a,student b)
{
	return a.grade>b.grade;
}
int main ()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].name>>s[i].num>>s[i].grade;
	}
	sort(s+1,s+1+n,cmp);
	cout<<s[1].name<<" "<<s[1].num<<endl<<s[n].name<<" "<<s[n].num;
	return 0;
}