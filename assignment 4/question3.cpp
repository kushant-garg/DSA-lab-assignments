#include <iostream>
using namespace std;

#define MAXLEN 100

typedef struct {
    int element[MAXLEN];
    int front, rear;
} queue;

queue initQ() { queue Q; Q.front=Q.rear=-1; return Q; }
int isEmpty(queue Q){ return (Q.front==-1 || Q.front>Q.rear); }
int isFull(queue Q){ return (Q.rear==MAXLEN-1); }

void enq(queue &Q,int x){
    if(isFull(Q))return;
    if(Q.front==-1)Q.front=0;
    Q.rear++; Q.element[Q.rear]=x;
}

int deq(queue &Q){
    if(isEmpty(Q))return -1;
    int x=Q.element[Q.front];
    Q.front++; return x;
}

int main() {
    queue Q = initQ();
    int n; cin>>n;
    for(int i=0;i<n;i++){ int x; cin>>x; enq(Q,x); }
    
    int half=n/2;
    queue first=initQ(), second=initQ();

    for(int i=0;i<half;i++) enq(first, deq(Q));
    while(!isEmpty(Q)) enq(second, deq(Q));

    queue result=initQ();
    while(!isEmpty(first) && !isEmpty(second)) {
        enq(result, deq(first));
        enq(result, deq(second));
    }

    while(!isEmpty(result))
        cout<<deq(result)<<" ";
}
