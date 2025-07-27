#include <bits/stdc++.h>
using namespace std;
string s[8];
int t,flag;
int main ()
{
	cin>>t;
	getchar();
	while(t--)
	{
		flag=0;
		for(int i=0;i<8;i++)
		{
			cin>>s[i];
		}
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				if(s[i][j]!='.')
				{
					while(i<8&&s[i][j]!='.')
					{
						cout<<s[i][j];
						i++;
					}
					flag=1;
				}
				if(flag)
				break;
			}
			if(flag) break;
		}
		cout<<endl;
	}
	return 0;
}