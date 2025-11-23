#include <iostream>
using namespace std;

struct D{ int d; D *p,*n; };

int main(){
    int n,x; cin>>n;
    D *h=0,*l=0;
    while(n--){
        cin>>x;
        D* t=new D;
        t->d=x; t->p=l; t->n=0;
        if(!h) h=t;
        else l->n=t;
        l=t;
    }
    int c=0;
    D* p=h;
    while(p){ c++; p=p->n; }
    cout<<c;
}
