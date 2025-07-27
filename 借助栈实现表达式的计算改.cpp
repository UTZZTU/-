#define Stack_init_size 100
#define Stack_add 10
#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdio>
typedef struct{
	char *base;
	char *top;
	int stacksize;
}SqStack1;
typedef struct{
	double *base;
	double *top;
	int stacksize;
}SqStack2;
void InitStack(SqStack1 &S)
{
	S.base=(char *)malloc(Stack_init_size*sizeof(char));
	if(!S.base)
		exit(1);
	***.top=S.base;
	S.stacksize=Stack_init_size;
	return;
}
void InitStack(SqStack2 &S)
{
	S.base=(double *)malloc(Stack_init_size*sizeof(double));
	if(!S.base)
		exit(1);
	***.top=S.base;
	S.stacksize=Stack_init_size;
	return;
}
void Push(SqStack1 &S,char e)
{
	if(***.top-S.base>=S.stacksize)
	{
		S.base=(char *)realloc(S.base,(S.stacksize+Stack_add)*sizeof(char));
		if(!S.base)
			exit(1);
		S.stacksize+=Stack_add;
	}
	****.top++=e;
	return;
}
void Push(SqStack2 &S,double e)
{
	if(***.top-S.base>=S.stacksize)
	{
		S.base=(double *)realloc(S.base,(S.stacksize+Stack_add)*sizeof(double));
		if(!S.base)
			exit(1);
		***.top=S.base+S.stacksize;
		S.stacksize+=Stack_add;
	}
	****.top++=e;
	return;
}
bool Pop(SqStack1 &S,char &e)
{
	if(S.base==***.top)
		return false;
	e=*(--***.top);
	return true;
}
bool Pop(SqStack2 &S,double &e)
{
	if(S.base==***.top)
		return false;
	e=*(--***.top);
	return true;
}
char GetTop(SqStack1 &S)
{
	if(S.base==***.top)
		return 0;
	return *(***.top-1);
}
double GetTop(SqStack2 &S)
{
	if(S.base==***.top)
		return 0;
	return *(***.top-1);
}
bool In(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')'||c=='#'||c=='^')
		return true;
	return false;
}
double todouble(char s[])  
{  
  double val, power;  
  int i=0, sign;     
  sign = (s[i] == '-')? -1 : 1;  
  if(s[i] == '+' || s[i] == '-')  
      i++;  
  for(val = 0.0; isdigit(s[i]); i++)  
  {  
      val = val * 10 + (s[i] - '0');  
  }  
  if(s[i] == '.')  
      i++; 
  for(power = 1.0; isdigit(s[i]); i++)  
  {  
      val = 10.0 * val + (s[i] - '0');     
      power *= 10;  
  }   
  return sign * val / power;  
}  
double power(double a,double b)
{
	double s=1.0;
	for(int i=0;i<b;i++)
		s=s*a;
	return s;
}
double Operate(double a,char theta,double b)
{
	switch(theta)
	{
	    case'+':return a+b;
		case'-':return a-b;
		case'*':return a*b;
		case'/':return a/b;
		case'^':return power(a,b);
		default:return 0;
	}
}
char Precede(char m,char n)
{
	 char Prior[8][8] = {     //  算符间的优先关系
     '>','>','<','<','<','>','>','<',
     '>','>','<','<','<','>','>','<',
     '>','>','>','>','<','>','>','<',
     '>','>','>','>','<','>','>','<',
     '<','<','<','<','<','=',' ','<',
     '>','>','>','>',' ','>','>','>',
     '<','<','<','<','<',' ','=','<',
	 '>','>','>','>','<','>','>','>'
};  
	 char ch[8]={'+','-','*','/','(',')','#','^'};
	 int i,j;
	 for(i=0;i<8;i++)
		 if(m==ch[i])
			 break;
	 for(j=0;j<8;j++)
		 if(n==ch[j])
			 break;
	 return Prior[i][j];
}
void perfect(char s[])
{
	char s1[100];
	int i,j,n;	
	i=j=0;
	if(s[0]=='-')
		s1[j++]='0';
	s1[j++]=s[i++];
	while(s[i])
	{
		if(s[i]=='-'&&In(s[i-1])&&s[i-1]!=')')
		{
			s1[j++]='0';
			s1[j++]=s[i++];
		}
		s1[j++]=s[i++];
	}
	s1[j]='\0';
	i=0;
	while(s1[i])
	{
		s[i]=s1[i];
		i++;
	}
	s[i]='\0';
}
double  EvaluateExpression()
{
	char x,theta,z[100][20];
	double a,b;
	int i,j=0,k=0;
	char s[100];
	gets(s);
	perfect(s);
	SqStack1 OPTR;//寄存运算符
	SqStack2 OPND;//寄存操作数和操作结果
	InitStack(OPTR);
	InitStack(OPND);
	Push(OPTR,'#');
	while(s[j]!='#'||GetTop(OPTR)!='#')
	{
		if(!In(s[j]))
		{
			i=0;
			while(isdigit(s[j])||s[j]=='.')
			{	
				z[k][i++]=s[j++];
			}
			Push(OPND,todouble(z[k]));
			k++;
		}
		else
		    switch(Precede(GetTop(OPTR),s[j])){

			    case'<':Push(OPTR,s[j]);j++;break;
			    case'=':Pop(OPTR,x);j++;break;
				case'>':Pop(OPTR,theta);
					    Pop(OPND,b);
						Pop(OPND,a);
						Push(OPND,Operate(a,theta,b));
						break;
		}
	}
	return GetTop(OPND); 
}
int main() 
{
    printf("%.2f\n",EvaluateExpression());
	return 0;
}
