#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int nextval[300];
void getnextval(string s){
int j=-1;
nextval[0]=-1;
for(int i=0;i<s.size();i++){
while(j!=-1&&s[i]!=s[j+1]){
j=nextval[j];
}
if(s[i]==s[j+1]) j++;
if(j==-1||s[i+1]!=s[j+1]) nextval[i]=j;
else nextval[i]=nextval[j];
}
}
int KMP(string text,string pattern){
int n=text.size(),m=pattern.size();
getnextval(pattern);
int ans=0,j=-1;
for(int i=0;i<n;i++){
while(j!=-1&&text[i]!=pattern[j+1]){
j=nextval[j];
}
if(text[i]==pattern[j+1]) j++;
if(j==m-1){
ans++;
j=nextval[j];
}
}
return ans;
}
int main(){
string pattern;
int n,i;
int num=0;
cin>>n;
getchar();
getline(cin,pattern);
for(i=0;i<n;i++){
string text;
getline(cin,text);
num+=KMP(text,pattern);
}
cout<<num<<endl;
return 0;
}

