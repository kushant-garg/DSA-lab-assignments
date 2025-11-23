#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = NULL;

void ins(int x){
    Node* t = new Node;
    t->data = x;
    t->next = NULL;
    if(!head){
        head = t;
        return;
    }
    Node* p = head;
    while(p->next) p = p->next;
    p->next = t;
}

void rev(){
    Node *p = head, *q = NULL, *r = NULL;
    while(p){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

void disp(){
    Node* p = head;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
}

int main(){
    int n, x;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        ins(x);
    }
    rev();
    disp();
}
