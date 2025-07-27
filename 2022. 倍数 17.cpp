#include <bits/stdc++.h>
using namespace std;
string add(string a,string b)
{
	string p;
	int jw=0,i,j;
	for(j=b.size()-1,i=a.size()-1;i>=0;i--,j--)
	{
		int num=b[j]-'0'+a[i]-'0'+jw;
		jw=num/2;
		num%=2;
		p+='0'+num;
	}
	for(j;j>=0;j--)
	{
		int num=b[j]-'0'+jw;
		jw=num/2;
		num%=2;
		p+='0'+num;
	}
	if(jw)
	p+='1';
	reverse(p.begin(),p.end());
	return p;
}
string u,v;
int main ()
{
	getline(cin,u);
	v=add(u,u+"0000");
	cout<<v;
	return 0;
}