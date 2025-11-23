#include <iostream>
using namespace std;

#define MAXLEN 100

typedef struct { int element[MAXLEN]; int front, rear; } queue;

queue initQ(){ queue Q; Q.front=Q.rear=-1; return Q; }
int isEmpty(queue Q){ return (Q.front==-1 || Q.front>Q.rear); }
int isFull(queue Q){ return (Q.rear==MAXLEN-1); }

void enq(queue &Q,int x){
    if(isFull(Q))return;
    if(Q.front==-1)Q.front=0;
    Q.rear++; Q.element[Q.rear]=x;
}

int deq(queue &Q){
    if(isEmpty(Q))return -1;
    int x=Q.element[Q.front]; Q.front++; return x;
}

int main(){
    queue q1=initQ(), q2=initQ();
    int ch,x;

    while(1){
        cout<<"1 push 2 pop 3 exit\n";
        cin>>ch;

        if(ch==1){
            cin>>x;
            enq(q2,x);
            while(!isEmpty(q1)) enq(q2, deq(q1));
            q1 = q2;
            q2 = initQ();
        }
        else if(ch==2){
            cout<<deq(q1)<<"\n";
        }
        else break;
    }
}
