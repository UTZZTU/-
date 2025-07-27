#include <bits/stdc++.h>
using namespace std;
int t;
string s[3];
bool judge(char c)
{
	if(s[0][0]==c&&s[0][1]==c&&s[0][2]==c) return true;
	if(s[1][0]==c&&s[1][1]==c&&s[1][2]==c) return true;
	if(s[2][0]==c&&s[2][1]==c&&s[2][2]==c) return true;
	if(s[0][0]==c&&s[2][0]==c&&s[1][0]==c) return true;
	if(s[0][1]==c&&s[1][1]==c&&s[2][1]==c) return true;
	if(s[0][2]==c&&s[1][2]==c&&s[2][2]==c) return true;
	if(s[0][0]==c&&s[1][1]==c&&s[2][2]==c) return true;
	if(s[0][2]==c&&s[1][1]==c&&s[2][0]==c) return true;
	return false;
}
int main ()
{
	cin>>t;
	getchar();
	while(t--)
	{
		for(int i=0;i<3;i++)
		{
			cin>>s[i];
		}
		if(judge('X'))
		{
			printf("X\n");
		}
		else if(judge('O'))
		{
			printf("O\n");
		}
		else if(judge('+'))
		{
			printf("+\n");
		}
		else printf("DRAW\n");
	}
	return 0;
}