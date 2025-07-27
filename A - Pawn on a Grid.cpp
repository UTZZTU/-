#include <iostream>
using namespace std;
int h,w,sum;
string a[10];
int main ()
{
	cin>>h>>w;
	for(int i=0;i<h;i++)
	cin>>a[i];
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(a[i][j]=='#')
			sum++;
		}
	}
	cout<<sum;
	return 0;
}