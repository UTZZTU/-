#include <bits/stdc++.h>
using namespace std;
int n,m;
string a[20],name,pp;
int main ()
{
	cin>>n>>m;
	getchar();
	for(int i=1;i<=m;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cin>>name;
		for(int i=1;i<=m;i++)
		{
			cin>>pp;
			string right=name+".zip/"+name+"/"+a[i]+"/"+a[i]+".cpp";
			if(pp==right)
			cout<<"Fusu is happy!"<<endl;
			else
			cout<<"Fusu is angry!"<<endl;
		}
	}
	return 0;
}