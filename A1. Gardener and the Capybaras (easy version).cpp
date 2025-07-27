#include <bits/stdc++.h>
using namespace std;
int t,flag;
string s,a,b,c;
bool judge(int i,int j)
{
	a=s.substr(0,i);
	b=s.substr(i,j-i);
	c=s.substr(j,s.size()-j);
	if(a<=b&&c<=b||b<=a&&b<=c)
	return true;
	else
	return false;
}
int main ()
{
	cin>>t;
	getchar();
	while(t--)
	{
		flag=0;
		cin>>s;
		for(int i=1;i<s.size();i++)
		{
			for(int j=i+1;j<s.size();j++)
			{
				if(judge(i,j))
				{
					flag=1;
					break;
				}
			}
			if(flag)
			break;
		}
		if(flag)
		cout<<a<<" "<<b<<" "<<c<<endl;
		else
		printf(":(\n");
	}
	return 0;
}