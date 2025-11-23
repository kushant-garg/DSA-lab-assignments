#include <iostream>
using namespace std;

#define MAXLEN 100

typedef struct {
    char element[MAXLEN];
    int front, rear;
} queue;

queue initQ(){ queue Q; Q.front=Q.rear=-1; return Q; }
int isEmpty(queue Q){ return (Q.front==-1 || Q.front>Q.rear); }
int isFull(queue Q){ return (Q.rear==MAXLEN-1); }

void enq(queue &Q,char x){
    if(isFull(Q))return;
    if(Q.front==-1)Q.front=0;
    Q.rear++; Q.element[Q.rear]=x;
}

char deq(queue &Q){
    if(isEmpty(Q))return '#';
    char x=Q.element[Q.front];
    Q.front++; return x;
}

int main(){
    queue Q=initQ();
    int freq[256]={0};
    string s; cin>>s;

    for(int i=0;i<s.length();i++){
        char c=s[i];
        freq[c]++;
        enq(Q,c);

        while(!isEmpty(Q) && freq[Q.element[Q.front]]>1)
            deq(Q);

        if(isEmpty(Q)) cout<<"-1 ";
        else cout<<Q.element[Q.front]<<" ";
    }
}
