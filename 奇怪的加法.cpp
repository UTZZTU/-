#include <bits/stdc++.h>
using namespace std;
string u,v,t;
int num;
string add(string u,string v)
{
	string res;
	if(u.size()<v.size())
	swap(u,v);
	int i,j;
	for(i=u.size()-1,j=v.size()-1;j>=0;i--,j--)
    {
    	num=u[i]-'0'+v[j]-'0';
    	num%=10;
    	res+='0'+num;
	}
	for(i;i>=0;i--)
	res+=u[i];
	reverse(res.begin(),res.end());
	return res;
}
int main ()
{
	while(cin>>u>>v)
	{
		int i=0;
		t=add(u,v);
		while(i<t.size()-1&&t[i]=='0')
		i++;
		for(i;i<t.size();i++)
		cout<<t[i];
		cout<<endl;
	}
	return 0;
}