#include<stdio.h>
int main()
{
    int b[201];
    int i;
    i=0;
    while(scanf("%d",&b[i])!=EOF){
        i++;
    }
    i=0;
    if(b[1]==0){
        printf("0 0\n");
    }
    else{
        while(b[i+1]!=0){
            if(i==0)
                printf("%d %d",b[i]*b[i+1],b[i+1]-1);
            else
                printf(" %d %d",b[i]*b[i+1],b[i+1]-1);
            i+=2;
        }
        printf("\n");
    }
    return 0;
}
