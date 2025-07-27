#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
	int a[4];
	while(cin>>a[0]>>a[1]>>a[2]>>a[3])
	{
		if(a[0]==0&&a[1]==0&&a[2]==0&&a[3]==0)
		break;
		else
		{
			sort(a,a+4);
			int p=-1;
			do
			{
				
				if(p==-1&&a[0]!=0)
				{
					p=a[0];
					cout<<a[0]<<a[1]<<a[2]<<a[3];
				}
				else
				{
					if(p!=a[0]&&a[0]!=0)
					{
						cout<<endl;
						cout<<a[0]<<a[1]<<a[2]<<a[3];
						p=a[0];
					}
					else 
					{
						if(a[0]!=0)
						cout<<" "<<a[0]<<a[1]<<a[2]<<a[3];
					}
					
				}	
			}while(next_permutation(a,a+4));
            cout<<endl;
		}
	}
	return 0;
}