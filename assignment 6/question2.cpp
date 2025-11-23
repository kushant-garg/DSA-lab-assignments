#include <iostream>
using namespace std;

struct N{
    int d;
    N* next;
};

void printCircular(N* head){
    if(!head) return;
    N* p=head;
    do{
        cout<<p->d<<" ";
        p=p->next;
    }while(p!=head);
    cout<<head->d;
}

int main(){
    int n,x;
    cin>>n;
    N* head=0,*last=0;
    while(n--){
        cin>>x;
        N* t=new N;
        t->d=x; t->next=0;
        if(!head){ head=last=t; t->next=head; }
        else{ last->next=t; last=t; last->next=head; }
    }
    printCircular(head);
}
