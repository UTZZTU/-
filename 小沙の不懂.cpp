#include <bits/stdc++.h>
using namespace std;
string a,b;
int flag;
int main ()
{
	cin>>a>>b;
	if(a==b)
	{
		cout<<"=";
	}
	else if(a.size()==b.size())
	{
		cout<<"!";
	}
	else
	{
		if(a.size()<b.size())
		{
			swap(a,b);
			flag=1;
		}
		int i=0,j=0;
		while(i<a.size()&&a[i]==a[0])
		i++;
		while(j<b.size()&&b[j]==a[0])
		j++;
		if(a.size()-i>b.size()-j)
		{
			if(flag)
			cout<<"<";
			else
			cout<<">";
		}
		else
		cout<<"!";
	}
	return 0;
}