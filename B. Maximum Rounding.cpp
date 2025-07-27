#include <bits/stdc++.h>
using namespace std;
int t;
string x;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>x;
		int pos=0x3f3f3f3f,num=0;
		for(int i=x.size()-1;i>=0;i--)
		{
			if(x[i]-'0'+num>=5)
			{
				if(x[i]=='9'&&num==1)
				{
					int j=i;
					while(j>=0&&x[j]=='9')
					{
						j--;
					}
					j++;
					pos=j;
					num=1;
					i=j;
					
				}
				else
				{
					num=1;
					pos=i;
				}
			}
			else
			{
				x[i]+=num;
				num=0;
			}
		}
//		cout<<"pos:"<<pos<<endl;
		if(num) cout<<"1";
//		int pp=x.size()-1;
		for(int i=0;i<x.size();i++)
		{
			if(i>=pos)
			{
				cout<<"0";
			}
			else
			{
				cout<<x[i];
			}
//			pp--;
		}
		cout<<endl;
	}
	return 0;
}