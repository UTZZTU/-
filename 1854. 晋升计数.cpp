#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int t1,t2,y1,y2,j1,j2,bj1,bj2,s1,s2,s3;
	cin>>t1>>t2>>y1>>y2>>j1>>j2>>bj1>>bj2;
	s3=bj2-bj1;
	s2=j2-(j1-s3);
	s1=y2-(y1-s2);
	cout<<s1<<endl<<s2<<endl<<s3;
	return 0;
}