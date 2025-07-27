#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	for(int i=0;i<=6;i++)
	{
		for(int j=0;j<60;j++)
		{
			for(int k=0;k<60;k++)
			{
				if(min(abs(5*i-j),60-abs(5*i-j))==2*min(abs(j-k),60-abs(j-k)))
				{
					cout<<i<<" "<<j<<" "<<k<<endl;
				}
			}
		}
	}
	return 0;
}