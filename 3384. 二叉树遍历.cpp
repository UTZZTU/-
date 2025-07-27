#include <bits/stdc++.h>
using namespace std;
void built()
{
	char c=getchar();
	if(c=='#') return;
	
	built();
	cout<<c<<" ";
	built();
}
int main ()
{
	built();
	return 0;
}