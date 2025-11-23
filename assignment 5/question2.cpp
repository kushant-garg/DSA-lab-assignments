#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head=NULL;

void insertEnd(int x){
    Node* t=new Node;
    t->data=x; t->next=NULL;
    if(!head){ head=t; return; }
    Node* p=head;
    while(p->next) p=p->next;
    p->next=t;
}

int delKey(int k){
    int cnt=0;
    while(head && head->data==k){
        Node* t=head; head=head->next; delete t; cnt++;
    }
    Node *p=head,*q=NULL;
    while(p){
        if(p->data==k){
            cnt++;
            q->next=p->next;
            delete p;
            p=q->next;
        }else{
            q=p; p=p->next;
        }
    }
    return cnt;
}

void disp(){
    Node* p=head;
    while(p){ cout<<p->data<<" "; p=p->next; }
}

int main(){
    int n,x,k;
    cin>>n;
    for(int i=0;i<n;i++){ cin>>x; insertEnd(x); }
    cin>>k;
    int c = delKey(k);
    cout<<c<<" ";
    disp();
}
