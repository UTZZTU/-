#include <iostream>
using namespace std;
int n,m,res,k;
string u[50];
int main ()
{
	cin>>n>>m;
	getchar();
	for(int i=0;i<n;i++)
	cin>>u[i];
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			k=0;
			for(int v=0;v<m;v++)
			{
				if(u[i][v]=='o'||u[j][v]=='o')
				k++;
			}
			if(k==m)
			res++;
		}
	}
	cout<<res;
	return 0;
}