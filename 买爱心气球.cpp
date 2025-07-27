#include <bits/stdc++.h>
using namespace std;
int t,m,n;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		if(m==0&&n==0)
		{
			printf("Bob\n");
		}
		else if(m==0&&n!=0)
		{
			printf("Alice\n");
		}
		else if(m!=0&&n==0)
		{
			if(m%3==0) printf("Bob\n");
			else printf("Alice\n");
		}
		else
		{
			if(m%3==0)
			{
				printf("Alice\n");
			}
			else
			{
				if(m%3==n) printf("Bob\n");
				else printf("Alice\n");
			}
		}
	}
	return 0;
}
/*
m 
n
m+n
0 0 bob
0 n alice
m 0 
    1 0 alice
    2 0 alice
    3 0 bob
    4 0 alice
    5 0 alice
    6 0 bob
    7 0 alice
    8 0 alice
    9 0 bob
    
m n
    1 n 
        1 1 bob
        1 2 alice
        1 3 alice
        1 n alice
    2 n
        2 1 alice
        2 2 bob
        2 3 alice
        2 n aclice
    3 n
        3 1 alice
        3 n alice
    4 n
        4 1 bob
        4 2 alice
*/