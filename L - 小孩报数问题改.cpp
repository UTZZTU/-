#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
const int N = 64;
const int N2 = 15;
char name[N][N2 + 1];
int main()
{
    int n, w, s, pos;
    while(scanf("%d", &n) != EOF) {
        for(int i=0; i<n; i++)
            scanf("%s", name[i]);
        scanf("%d,%d", &w, &s);
        pos = w - 2;
        for(int i=0; i<n; i++) {
            for(int j=0; j<s; j++) {    
                pos++;              
                if(pos >= n)
                    pos %= n;       
                if(name[pos][0] == '\0')
                    j--;
            }
            printf("%s\n", name[pos]);  
 
            name[pos][0] = '\0';           
        }
    }
    return 0;
}
