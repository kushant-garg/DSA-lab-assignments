#include <iostream>
using namespace std;

struct D{
    int data;
    D *prev,*next;
};

D* head2=0;

void ins(int x,int pos){
    D* t=new D;
    t->data=x;
    t->prev=t->next=0;

    if(!head2){ head2=t; return; }

    if(pos==1){
        t->next=head2;
        head2->prev=t;
        head2=t;
        return;
    }
    D* p=head2;
    for(int i=1;i<pos-1 && p->next;i++) p=p->next;
    t->next=p->next;
    if(p->next) p->next->prev=t;
    t->prev=p;
    p->next=t;
}

void delVal(int x){
    D* p=head2;
    while(p){
        if(p->data==x){
            if(p==head2){
                head2=head2->next;
                if(head2) head2->prev=0;
            } else {
                p->prev->next=p->next;
                if(p->next) p->next->prev=p->prev;
            }
            delete p;
            return;
        }
        p=p->next;
    }
}

bool srch(int x){
    D* p=head2;
    while(p){
        if(p->data==x) return true;
        p=p->next;
    }
    return false;
}

int main(){
    int c,v,pos;
    while(cin>>c){
        if(c==1){ cin>>v>>pos; ins(v,pos); }
        else if(c==2){ cin>>v; delVal(v); }
        else if(c==3){ cin>>v; cout<<(srch(v)?"Found":"No")<<"\n"; }
        else break;
    }
}
