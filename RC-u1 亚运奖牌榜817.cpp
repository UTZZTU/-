#include <bits/stdc++.h>
using namespace std;
int n,p[2][4],c,k;
int main ()
{
	cin>>n;
	while(n--)
	{
		cin>>c>>k;
		p[c][k]++;
	}
	cout<<p[0][1]<<" "<<p[0][2]<<" "<<p[0][3]<<endl;
	cout<<p[1][1]<<" "<<p[1][2]<<" "<<p[1][3]<<endl;
	if(p[0][1]>p[1][1]||p[0][1]==p[1][1]&&p[0][2]>p[1][2]||p[0][1]==p[1][1]&&p[0][2]==p[1][2]&&p[0][3]>p[1][3])
	cout<<"The first win!";
	else
	cout<<"The second win!";
	return 0;
}