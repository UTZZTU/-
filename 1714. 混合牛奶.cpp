#include <bits/stdc++.h>
using namespace std;
int c[3],m[3];
int main ()
{
	for(int i=0;i<3;i++)
	cin>>c[i]>>m[i];
	int i=0;
	while(i<100)
	{
		int cz=min(m[i%3],c[(i+1)%3]-m[(i+1)%3]);
		m[i%3]-=cz;
		m[(i+1)%3]+=cz;
		i++;
	}
	cout<<m[0]<<endl<<m[1]<<endl<<m[2];
	return 0;
}