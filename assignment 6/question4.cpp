#include <iostream>
using namespace std;

struct D{ char c; D *p,*n; };

int main(){
    int n; cin>>n;
    char x;
    D *h=0,*l=0;
    for(int i=0;i<n;i++){
        cin>>x;
        D* t=new D;
        t->c=x; t->p=l; t->n=0;
        if(!h) h=t;
        else l->n=t;
        l=t;
    }
    D *a=h,*b=l;
    bool ok=true;
    while(a && b && a!=b && b->n!=a){
        if(a->c!=b->c){ ok=false; break; }
        a=a->n; b=b->p;
    }
    cout<<(ok?"True":"False");
}
