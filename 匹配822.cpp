#include <bits/stdc++.h>
using namespace std;
int n,a,b;
int read() {
    char ch;
    int x = 0;
    bool f = true;
    for (ch = getchar(); !isdigit(ch); ch = getchar())
        if (ch == '-')
            f ^= f;
    for (; isdigit(ch); ch = getchar())
        x = (x << 3) + (x << 1) + ch - 48;
    return f ? x : -x;
}
int main ()
{
	n=read();
// 	for(int i=1;i<=n;i++)
// 	{
// 		scanf("%d%d",&a,&b);
// 	}
	printf("%d",n);
	return 0;
}