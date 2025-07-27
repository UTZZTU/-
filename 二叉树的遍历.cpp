#include<bits/stdc++.h>
using namespace std;
typedef struct node											
{
	struct node * l,* r;
	char value;
}Node;
Node *buildtree(char a[],char b[],int pl,int pr,int il,int ir)	
{
	if (pl<=pr){
		Node * p=(Node*)malloc(sizeof(Node));			
		p->value=a[pl];
		int k =il;
		while(b[k]!=a[pl]) k++;
		p->l=buildtree(a,b,pl+1,pl+k-il,il,k-1);		
		p->r=buildtree(a,b,pl+k-il+1,pr,k+1,ir);	
		return p;
	}
	else return NULL;
}
void post(Node * w){
	if (w!=NULL){
		post(w->l);
		post(w->r);
		printf("%c",w->value);											
	}
}

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		char a[26],b[26];
		scanf("%s%s",a,b);
		int len = strlen(a);
		Node *temp =buildtree(a,b,0,len-1,0,len-1);	
		post(temp);
		if(i!=t-1) cout<<endl;										
	}
	return 0;
}
