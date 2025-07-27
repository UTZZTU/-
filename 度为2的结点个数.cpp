#include<bits/stdc++.h>
using namespace std;
struct edge{
    char value;
    edge* l;
    edge* r;
};
int js;
void build(edge* &temp,char *pre,char *in,int len){
    temp=new edge;
    if(temp!=NULL){
        if(len<=0){
            temp = NULL;
            return ;
        }
        int index = 0;
        while(index<len&&*(pre)!=*(in+index))
            index++;
        temp->value = *(pre);
        build(temp->l,pre+1,in,index);
        build(temp->r,pre+1+index,in+1+index,len-(index+1));
    }
    return;
}
void post(edge* edge){
	if(edge==NULL)
        return;
	if(edge->l!=NULL&&edge->r!=NULL)
		js++;
    post(edge->l);
    post(edge->r);
}
int main(){
	int n;
	cin>>n;
    char pre[101];  
    char in[101]; 
    for(int i=1;i<=n;i++){
    	cin>>pre>>in;
    	js=0;
        edge* tree;
        int len = strlen(pre);
        build(tree,pre,in,len);
        post(tree);
        cout<<js;
        if(i!=n) cout<<endl;
    }
    return 0;
}