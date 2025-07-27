#include <stdio.h>
int a[100000];
int main() {
    int n, i, j;
    scanf("%d", &n);
    //用来表示之前阶乘的位数，初始化一位数
    int temp = 1;
    //初始相乘的数也为一
    a[0] = 1;
    //一层循环，使下一个数和之前所乘的数的每一位数相乘
    //注：这层循环以后，a数组中每一位数都不一定是一个一位数 
    for (i = 2; i <= n; i++) {
        for (j = 0; j < temp; j++) {
            a[j] *= i ;        
        }                 
        //这层循环使得a数组每个数都是个一位数
        for (j = 0; j < temp; j++) {
            a[j + 1] += a[j] / 10;  
            a[j] %= 10;  
        }
        //判断最高位，进行进位
        if (a[j] > 0) {
            while (a[j] > 9) {
                a[j + 1] += a[j] / 10;
                a[j] %= 10;   
                j++;
            }
        //j当前的值可表示为求完一轮阶乘的位数，将j传递给temp!
            temp = j + 1;
        }
    }
    //从后往前依次输出
    for (i = temp - 1; i >= 0; i--)
        printf("%d", a[i]);
    printf("\n");
    return 0;
}

