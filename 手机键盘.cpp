#include <stdio.h>
/*九键布局 abc def ghi jkl mno pqrs tuv wxyz*/

char getkey(char a){    //确定字符串中的每一个字符究竟在哪个键上
    if(a>='a'&&a<='c') return 'a';
    if(a>='d'&&a<='f') return 'd';
    if(a>='g'&&a<='i') return 'g';
    if(a>='j'&&a<='l') return 'j';
    if(a>='m'&&a<='o') return 'm';
    if(a>='p'&&a<='s') return 'p';
    if(a>='t'&&a<='v') return 't';
    if(a>='w'&&a<='z') return 'w';
    return '\0';

}

int main(){
    char s[101];
    while(scanf("%s",s)!=EOF){
        int t=0;
        int i;
        //遍历s中的每一个字符
        for(i=0;s[i]!='\0';i++){
            char c=getkey(s[i]);
            //当相邻两次按同一个键时
            if(i>0&&(getkey(s[i])==getkey(s[i-1]))){
                t+=2;
            }
            t+=(s[i]-c+1);
        }
        printf("%d\n",t);
    }
    return 0;
}