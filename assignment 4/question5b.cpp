#include<iostream>
#include<queue>
using namespace std;

queue<int> q;

void pushh(int x){
    q.push(x);
    int s=q.size();
    while(s>1){
        q.push(q.front());
        q.pop();
        s--;
    }
}

int popp(){
    if(q.empty()) return -1;
    int z=q.front(); q.pop();
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
