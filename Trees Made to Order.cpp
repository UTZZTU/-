#include<iostream>
#include<string>
#include <stdio.h>
using namespace std;
 
int c[50];
int a[50][50];
int indexes[50];
int sum[50];
const int MAX = 500000000;
int maxSeq;
string str;
 
void generate() {
int tmp = 1;
maxSeq = 1;
c[0] = 1, c[1] = 1;
sum[0] = 0, indexes[0] = 0;
sum[1] = 1, indexes[1] = 1;
while(sum[maxSeq] < MAX) {
   ++maxSeq;
   c[maxSeq] = 0;
   for(int i = 0; i < maxSeq; i++)
    c[maxSeq] += c[i]*c[maxSeq-1-i];
   sum[maxSeq] = sum[maxSeq-1] + c[maxSeq];
} 
 
for(int i = 0; i <= maxSeq; i++) 
   for(int j = 0; j <= maxSeq; j++) 
    a[i][j] = c[i]*c[j];
   
for(int i = 1; i <= maxSeq + 1; i++) 
   indexes[i] = sum[i-1] + 1;
}
 
int findIndex(int value) {
int i = 1;
while(!(value >= indexes[i] && value < indexes[i+1]))
   ++i;
return i ;
}
 
void solve(int value) {
if(value <= 0)
   return ;
if(value == 1)
   str += "X";
else if(value == 2)
   str += "X(X)";
else if(value == 3)
   str += "(X)X";
else if(value == 4) 
   str += "X(X(X))";
else {
   int index = findIndex(value);  
   int remain = value - sum[index-1];
   
   int left, right;
   int i = 0;
   while(remain - a[i][index-1-i] > 0) {
    remain -= a[i][index-1-i];
    ++i;
   }
   left = i;
   right = index - 1 - i;   
   if(left > 0) {
    int leftValue = sum[left-1] + remain/c[right];
    if(remain%c[right] != 0)
     ++leftValue;
    if(leftValue > 0) {
     str += "(";
     solve(leftValue);
     str += ")";
    }
   }  
   str += "X";
   if(right > 0) {
    int tmp = remain - remain/c[right]*c[right];
    if(tmp == 0)
     tmp = c[right];
    int rightValue = sum[right-1] + tmp;  
    if(rightValue > 0) {
     str += "(";
     solve(rightValue);
     str += ")";
    }
   }  
}
}
 
void cal(int value) {
str = "";
solve(value);
cout<<str<<endl;
}
 
int main() {
generate();
int value;
while(scanf("%d", &value) && value != 0) {
   cal(value);
}
return 0;
}