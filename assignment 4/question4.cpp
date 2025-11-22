#include<iostream>
#include<queue>
using namespace std;

int main(){
    string s; 
    while(cin>>s){
        queue<char> q;
        int cnt[256]={0};
        for(char c:s){
            cnt[c]++;
            q.push(c);
            while(!q.empty() && cnt[q.front()]>1) q.pop();
            if(q.empty()) cout<<"-1 ";
            else cout<<q.front()<<" ";
        }
        break;
    }
}
