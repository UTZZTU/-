#include<stdio.h>
#define len 1000 //可根据最终数据长度修改 
int main()
{
    int i,j,n,flag,t,jinwei;
    while(~scanf("%d",&n))
    {
        int a[n+1];
        int lcm[len]={0}; //初始化 
        lcm[0]=1; //首元素设置为1 
        for(i=1;i<=n;i++) a[i]=i; 
        for(i=4;i<=n;i++) //2,3的质因数为其本身，所以从4开始分解 
        {
            for(j=2;j<=i/2;j++) //遍历从a[2]开始到a[i/2]的每一个数 
            {
                if(a[i]%a[j]==0) a[i]/=a[j]; //若a[j]为a[i]的质因数，则将a[i]分解 
            }
        }
        //分解完所有数后执行大数乘法算法
        jinwei=j=0;
        for(i=2;i<=n;i++)
        {
            if(a[i]!=1) // 所有质因数之积即为最小公倍数，故跳过 1 
            {
                flag=j;
                j=-1;
                while(j<flag || jinwei)
                {
                    j++;
                    t=lcm[j]*a[i];
                    lcm[j]=(t+jinwei)%10;
                    jinwei=(t+jinwei)/10;
                }
            }
        }
        for(i=j;i>=0;i--) printf("%d",lcm[i]); //输出最小公倍数 
        printf("\n");
    }
    return 0;
}