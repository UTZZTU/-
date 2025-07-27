#include <bits/stdc++.h>
using namespace std;
int pos=26+26*26;
int main ()
{
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++)
		{
			for(int k=0;k<26;k++)
			{
				pos++;
				if(pos==2022)
				{
					printf("%c%c%c",('A'+i),('A'+j),('A'+k));
					return 0;
				}
			}
		}
	}
	return 0;
}
//蓝桥杯模拟赛2023-A