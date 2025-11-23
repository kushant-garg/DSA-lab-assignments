#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = NULL;

void insBeg(int x){
    Node* t = new Node;
    t->data = x;
    t->next = head;
    head = t;
}

void insEnd(int x){
    Node* t = new Node;
    t->data=x;
    t->next=NULL;
    if(head==NULL){ head=t; return; }
    Node* p = head;
    while(p->next) p=p->next;
    p->next=t;
}

void insBefore(int val,int x){
    if(head==NULL) return;
    if(head->data==val){
        insBeg(x); return;
    }
    Node *p=head,*q=NULL;
    while(p && p->data!=val){
        q=p;
        p=p->next;
    }
    if(!p) return;
    Node* t=new Node;
    t->data=x;
    t->next=p;
    q->next=t;
}

void insAfter(int val,int x){
    Node* p=head;
    while(p && p->data!=val) p=p->next;
    if(!p) return;
    Node* t=new Node;
    t->data=x;
    t->next=p->next;
    p->next=t;
}

void delBeg(){
    if(!head) return;
    Node* t=head;
    head=head->next;
    delete t;
}

void delEnd(){
    if(!head) return;
    if(!head->next){ delete head; head=NULL; return; }
    Node *p=head,*q=NULL;
    while(p->next){ q=p; p=p->next; }
    q->next=NULL;
    delete p;
}

void delVal(int v){
    if(!head) return;
    if(head->data==v){
        delBeg();
        return;
    }
    Node *p=head,*q=NULL;
    while(p && p->data!=v){
        q=p; p=p->next;
    }
    if(!p) return;
    q->next=p->next;
    delete p;
}

void searchNode(int v){
    Node *p=head; int pos=1;
    while(p){
        if(p->data==v){ cout<<"Found at "<<pos<<"\n"; return; }
        pos++; p=p->next;
    }
    cout<<"Not found\n";
}

void display(){
    Node* p=head;
    while(p){ cout<<p->data<<" "; p=p->next; }
    cout<<"\n";
}

int main(){
    int ch,x,val;
    while(1){
        cout<<"1 insBeg 2 insEnd 3 insBefore 4 insAfter 5 delBeg 6 delEnd 7 delVal 8 search 9 display 0 exit\n";
        cin>>ch;
        if(ch==0) break;
        if(ch==1){ cin>>x; insBeg(x); }
        else if(ch==2){ cin>>x; insEnd(x); }
        else if(ch==3){ cin>>val>>x; insBefore(val,x); }
        else if(ch==4){ cin>>val>>x; insAfter(val,x); }
        else if(ch==5) delBeg();
        else if(ch==6) delEnd();
        else if(ch==7){ cin>>x; delVal(x); }
        else if(ch==8){ cin>>x; searchNode(x); }
        else if(ch==9) display();
    }
}
