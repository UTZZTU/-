#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    char n[105];
    int s, i;
    scanf("%s %d", n, &s);
    int len = strlen(n);
    for(int j = 1; j <= s; j++) {
        i = 0;
        while(i < len && n[i] <= n[i + 1]) {
            i++;
        }
        while(i < len) {
            n[i] = n[i + 1];
            i++;
        }
    }
    len = strlen(n);
    for(i = 0; i < len; i++) {
        if(n[i] != '0'){
            break;
        }
    }
    if(i == len) {
        printf("0\n");
    } else {
        for(int j = i;j<len;j++){
            printf("%c",n[j]);
        }
        printf("\n");
    }
    return 0;
}
