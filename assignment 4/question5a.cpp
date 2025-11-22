#include<iostream>
#include<queue>
using namespace std;

queue<int> q1,q2;

void pushh(int x){
    q2.push(x);
    while(!q1.empty()){ q2.push(q1.front()); q1.pop(); }
    swap(q1,q2);
}

int popp(){
    if(q1.empty()) return -1;
    int z=q1.front(); q1.pop();
    return z;
}

int main(){
    int c,x;
    while(cin>>c){
        if(c==1){ cin>>x; pushh(x); }
        else if(c==2) cout<<popp()<<"\n";
        else break;
    }
}
