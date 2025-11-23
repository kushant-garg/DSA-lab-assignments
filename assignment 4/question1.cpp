#include<iostream>
using namespace std;

#define MAX 50

int q[MAX], frontt=-1, rear=-1;

void enqueue(int x){
    if(rear==MAX-1) return;
    if(frontt==-1) frontt=0;
    q[++rear]=x;
}

int dequeue(){
    if(frontt==-1 || frontt>rear) return -1;
    return q[frontt++];
}

int isEmpty(){
    return (frontt==-1 || frontt>rear);
}

int isFull(){
    return rear==MAX-1;
}

void display(){
    for(int i=frontt;i<=rear;i++) cout<<q[i]<<" ";
    cout<<"\n";
}

int peek(){
    if(isEmpty()) return -1;
    return q[frontt];
}

int main(){
    int ch,x;
    while(1){
        cin>>ch;
        if(ch==1){ cin>>x; enqueue(x); }
        else if(ch==2) cout<<dequeue()<<"\n";
        else if(ch==3) cout<<isEmpty()<<"\n";
        else if(ch==4) cout<<isFull()<<"\n";
        else if(ch==5) display();
        else if(ch==6) cout<<peek()<<"\n";
        else break;
    }
}
