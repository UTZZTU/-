#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int a[105];
char ch[105];
int res[105] = { 0 };
int main()
{
	cin >> ch;
	int cnt= 0;
	for (int i = 0; i <strlen(ch); i++)
	{
		a[++cnt] = ch[i] - '0';
	}
	int m;
	cin >> m;
 
	int k = 0;
	int l = 1, r = m+1;//每次查找的范围
	int minloc = 1;//记录每次查找到的最小值的下标
	int j;
	 while(k<cnt-m)
	{
		int minn = 0x3f3f3f3f;
		for ( j = l; j <= r; j++)
			if (a[j] < minn)
			{
				minn = a[j];
				minloc = j;
			}
		l = minloc+ 1;
		r++;
		res[++k] = minn;
	}
 
	 //处理前导零
	 int sta = 1;
	 int end = k;
	 while (res[sta] == 0 && k > 1)
	 {
		 sta++;
		 k--;
	 }
 
	for (int i = sta; i <= end; i++) cout<<res[i];
	return 0;
}