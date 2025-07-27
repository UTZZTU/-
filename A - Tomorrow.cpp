#include <bits/stdc++.h>
using namespace std;
int m,d,yy,mm,dd;
int main ()
{
	cin>>m>>d;
	cin>>yy>>mm>>dd;
	dd+=1;
	if(dd>d) dd=1,mm++;
	if(mm>m) yy++,mm=1;
	cout<<yy<<" "<<mm<<" "<<dd;
	return 0;
}