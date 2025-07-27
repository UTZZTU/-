#include <bits/stdc++.h>
using namespace std;
int s1[10],s2[10],pd;
int main ()
{
	string a,b;
	cin>>a;
	int jw=0,u;
	for(int i=a.size()-1;i>=0;i--)
	{
		s1[a[i]-'0']++;
		u=2*(a[i]-'0')+jw;
		jw=u/10;
		u=u%10;
		s2[u]++;
		b+='0'+u;
	}
	if(jw)
	{
		b+='0'+jw;
		s2[jw]++;
	}
	reverse(b.begin(),b.end());
	for(int i=0;i<10;i++)
	{
		if(s1[i]!=s2[i])
		{
			pd=1;
			break;
		}
   }
	if(pd)
	cout<<"No"<<endl;
	else
	cout<<"Yes"<<endl;
	cout<<b;
	return 0;
}