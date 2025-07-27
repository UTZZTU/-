#include <iostream>
using namespace std;
int main ()
{
	int s,f,t;
	cin>>s>>f>>t;
	t%=24*60;
	s+=t/60;
	t%=60;
	f+=t;
	s+=f/60;
	f%=60;
	s%=24;
	printf("%d %d",s,f);
	return 0;
}