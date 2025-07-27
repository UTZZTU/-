#include <bits/stdc++.h>
using namespace std;
string u,v;
string fun(string a,string b)
{
	string c;
	if(a.size()<b.size())
	swap(a,b);
	int jw=0,num,i,j;
	for(i=a.size()-1,j=b.size()-1;j>=0;i--,j--)
	{
		num=a[i]-'0'+b[j]-'0'+jw;
		jw=num/10;
		num%=10;
		c+='0'+num;
	}
	for(i;i>=0;i--)
	{
		num=a[i]-'0'+jw;
		jw=num/10;
		num%=10;
		c+='0'+num;
	}
	if(jw)
	c+='1';
	reverse(c.begin(),c.end());
	return c;
}
int main ()
{
	while(cin>>u>>v)
	cout<<fun(u,v)<<endl;
	return 0;
}