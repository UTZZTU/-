#include <bits/stdc++.h>
using namespace std;
int a[100010],n,res;
vector<int> vec[4];
int main ()
{
	cin>>n;
	if(n==1||n==2||n==3||n==7)
	cout<<-1;
	else
	{
		if(n==4)
		{
			cout<<"3 4 1 2";
		}
		else if(n==5)
		{
			cout<<"3 4 5 1 2";
		}
		else if(n==6)
		{
			cout<<"4 5 6 1 2 3";
		}
		else if(n==8)
		{
			cout<<"3 4 1 2 7 8 5 6";
		}
		else if(n==9)
		{
			cout<<"3 4 5 1 2 8 9 6 7";
		}
		else if(n==10)
		{
			cout<<"4 5 6 1 2 3 9 10 7 8";
		}
		else if(n==11)
		{
			cout<<"4 5 6 1 2 3 9 10 11 7 8";
		}
		else
		{
			res=0;
			for(int i=12;i<=n;i++)
			{
				vec[res].push_back(i-1);
				vec[res].push_back(i);
				vec[res].push_back(i-3);
				vec[res].push_back(i-2);
				if(i==n)
				{
					if(res==0)
					cout<<"3 4 1 2 7 8 5 6 ";
					else if(res==1)
					cout<<"3 4 5 1 2 8 9 6 7 ";
					else if(res==2)
					cout<<"4 5 6 1 2 3 9 10 7 8 ";
					else
					cout<<"4 5 6 1 2 3 9 10 11 7 8 ";
					for(int j=0;j<vec[res].size();j++)
					{
						cout<<vec[res][j]<<" ";
					}
					return 0;
				}
				res++;
				res%=4;
			}
		}
	}
	return 0;
}