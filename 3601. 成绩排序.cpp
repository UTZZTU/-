#include <bits/stdc++.h>
using namespace std;
struct people
{
	int score,age;
	string name;
}s[1010];
bool cmp(people a,people b)
{
	if(a.score!=b.score)
	return a.score<b.score;
	else if(a.name!=b.name)
	return a.name<b.name;
	else
	return a.age<b.age;
	
}
int n;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>s[i].name>>s[i].age>>s[i].score;
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++)
	cout<<s[i].name<<" "<<s[i].age<<" "<<s[i].score<<endl;
	return 0;
}