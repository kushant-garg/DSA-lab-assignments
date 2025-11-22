#include<iostream>
using namespace std;

#define N 50

int cq[N], f=-1, r=-1;

void enqueue(int x){
    if((r+1)%N==f) return;
    if(f==-1) f=0;
    r=(r+1)%N;
    cq[r]=x;
}

int dequeue(){
    if(f==-1) return -1;
    int z=cq[f];
    if(f==r){ f=r=-1; }
    else f=(f+1)%N;
    return z;
}

int isEmpty(){ return f==-1; }

int isFull(){ return (r+1)%N==f; }

void display(){
    if(f==-1) return;
    int i=f;
    while(i!=r){
        cout<<cq[i]<<" ";
        i=(i+1)%N;
    }
    cout<<cq[r]<<"\n";
}

int peek(){
    if(f==-1) return -1;
    return cq[f];
}

int main(){
    int c,x;
    while(1){
        cin>>c;
        if(c==1){ cin>>x; enqueue(x); }
        else if(c==2) cout<<dequeue()<<"\n";
        else if(c==3) cout<<isEmpty()<<"\n";
        else if(c==4) cout<<isFull()<<"\n";
        else if(c==5) display();
        else if(c==6) cout<<peek()<<"\n";
        else break;
    }
}
