#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head=0;

void insertAny(int x, int pos){
    Node* t=new Node;
    t->data=x; t->next=t;
    if(!head){ head=t; return; }

    if(pos==1){
        Node* p=head;
        while(p->next!=head) p=p->next;
        t->next=head;
        p->next=t;
        head=t;
        return;
    }

    Node* p=head;
    for(int i=1;i<pos-1 && p->next!=head;i++) p=p->next;
    t->next=p->next;
    p->next=t;
}

void deleteVal(int x){
    if(!head) return;
    Node *p=head,*q=0;
    do{
        if(p->data==x){
            if(p==head){
                Node* last=head;
                while(last->next!=head) last=last->next;
                if(last==head){ head=0; delete p; return; }
                head=head->next;
                last->next=head;
            } else {
                q->next=p->next;
            }
            delete p;
            return;
        }
        q=p; p=p->next;
    } while(p!=head);
}

bool searchNode(int x){
    if(!head) return false;
    Node* p=head;
    do{
        if(p->data==x) return true;
        p=p->next;
    } while(p!=head);
    return false;
}

int main(){
    int c,v,pos;
    while(true){
        cin>>c;
        if(c==1){ cin>>v>>pos; insertAny(v,pos); }
        else if(c==2){ cin>>v; deleteVal(v); }
        else if(c==3){ cin>>v; cout<<(searchNode(v)?"Found":"NotFound")<<"\n"; }
        else break;
    }
}
