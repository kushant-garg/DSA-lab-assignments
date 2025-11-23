#include <iostream>
using namespace std;

struct N{ int d; N* n; };

bool isCirc(N* h){
    if(!h) return false;
    N* p=h->n;
    while(p && p!=h) p=p->n;
    return p==h;
}

int main(){
    int n,x; cin>>n;
    N *h=0,*l=0;
    while(n--){
        cin>>x;
        N* t=new N;
        t->d=x; t->n=0;
        if(!h) h=l=t;
        else{ l->n=t; l=t; }
    }
    if(h) l->n=h; // making circular manually
    cout<<(isCirc(h)?"True":"False");
}
