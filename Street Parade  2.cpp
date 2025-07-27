#include<cstdio>
#include<cstring>
int n,i,a[1005],x,k,top;
int main(){
    while(scanf("%d",&n)&&n){
        top=0;k=1;
        for (i=1;i<=n;i++){
            scanf("%d",&x);
            a[++top]=x;
            while(top&&a[top]==k){top--;k++;}
        }
        if (!top)printf("yes\n");else printf("no\n");
    }
}