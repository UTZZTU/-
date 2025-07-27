#include <bits/stdc++.h>
using namespace std;
string letter[26][7],u;
char s[15];
int js;
int main ()
{
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<7;j++)
		{
			getline(cin,u);
			letter[i][j]=u;
		}
	}
	getline(cin,u);
	for(int i=0;i<u.size();i++)
	{
		while((u[i]<'A'||u[i]>'Z')&&i<u.size())
		i++;
		while(u[i]>='A'&&u[i]<='Z')
		{
			s[js++]=u[i];
			i++;
		}
		for(int j=0;j<7;j++)
		{
			for(int k=0;k<js;k++)
			{
				if(k!=0)
				cout<<" ";
				cout<<letter[s[k]-'A'][j];
			}
			if(j!=6)
			cout<<endl;
		}
		while((u[i]<'A'||u[i]>'Z')&&i<u.size())
		i++;
		if(i>=u.size()-1)
		break;
		else
		cout<<endl<<endl;
		i--;
		js=0;
	}
	return 0;
}