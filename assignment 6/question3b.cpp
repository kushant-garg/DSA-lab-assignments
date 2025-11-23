#include <iostream>
using namespace std;

struct C{ int d; C* n; };

int main(){
    int n,x; cin>>n;
    C *h=0,*l=0;
    while(n--){
        cin>>x;
        C* t=new C; t->d=x;
        if(!h){ h=l=t; t->n=h; }
        else{ l->n=t; l=t; l->n=h; }
    }
    int c=0;
    if(h){
        C* p=h;
        do{ c++; p=p->n; }while(p!=h);
    }
    cout<<c;
}
