#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int main(){
    Node* head=NULL,*t,*p;
    int n,x; 
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        t=new Node;
        t->data=x;
        t->next=NULL;
        if(!head) head=t;
        else{
            p=head;
            while(p->next) p=p->next;
            p->next=t;
        }
    }
    Node *slow=head,*fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    if(slow) cout<<slow->data;
}
