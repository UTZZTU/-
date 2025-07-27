#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> a[30];
	for(int i = 0; i < 20; i++) 
	{ 
		for(int j = 0; j < 20; j++) 
		{
			a[i].push_back(i*j);
		}
	}
	for(int i = 0; i < 20; i++) 
	{ 
		for(int j = 0; j < 20; j++) 
		{
		  printf("%d\n",a[i][j]); 
		}
	}
}
