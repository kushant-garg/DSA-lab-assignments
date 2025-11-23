#include <iostream>
using namespace std;

#define MAXLEN 100

typedef struct {
    int a[MAXLEN];
    int f, r;
} queue1;

queue1 initq() {
    queue1 q;
    q.f = q.r = -1;
    return q;
}

int qempty(queue1 q) {
    return (q.f == -1 || q.f > q.r);
}

int qfull(queue1 q) {
    return (q.r == MAXLEN-1);
}

void enq(queue1 &q, int x) {
    if(qfull(q)) return;
    if(q.f == -1) q.f = 0;
    q.a[++q.r] = x;
}

int deq(queue1 &q) {
    if(qempty(q)) return -1;
    return q.a[q.f++];
}

int qsize(queue1 q) {
    if(qempty(q)) return 0;
    return q.r - q.f + 1;
}

int qfront(queue1 q) {
    if(qempty(q)) return -1;
    return q.a[q.f];
}

struct Stack {
    queue1 q;
};

Stack initS() {
    Stack s;
    s.q = initq();
    return s;
}

void push(Stack &s, int x) {
    enq(s.q, x);
    int k = qsize(s.q);
    for(int i=0;i<k-1;i++){
        int t = deq(s.q);
        enq(s.q,t);
    }
}

int pop(Stack &s) {
    return deq(s.q);
}

int top(Stack s) {
    return qfront(s.q);
}

int empty(Stack s) {
    return qempty(s.q);
}

// ---------------- main ----------------

int main() {
    Stack s = initS();
    push(s,10);
    push(s,20);
    push(s,30);
    cout<<pop(s)<<endl;
    cout<<top(s)<<endl;
    push(s,40);
    cout<<pop(s)<<endl;
}
