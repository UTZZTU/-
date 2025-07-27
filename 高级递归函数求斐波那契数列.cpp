#include <stdio.h>
#include<math.h> 
int Fibonacci(int n) {
        if(n < 2)
            return n;
        int f = 0, g = 1;
        int result = 0;
        for(int i = 1; i < n; i++){
            result = f + g;
            f = g;
            g = result;
        }
        return result;
    }
int main ()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		printf("%8d",Fibonacci(i));
	}
	return 0;
}
