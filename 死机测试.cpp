#include <vector>
#include <stdio.h>
using namespace std;
int main ()
{
	int n,w;
	vector<vector<int> > a(3);
	scanf("%d%d",&w,&n);
	a[w].push_back(n);
	printf("%d",a[w][0]);
 } 
