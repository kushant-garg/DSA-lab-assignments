#include<iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int a[100];
    for(int i=0;i<n;i++) cin>>a[i];

    int mid=n/2;
    int i=0, j=mid;

    while(i<mid && j<n){
        cout<<a[i]<<" "<<a[j]<<" ";
        i++; j++;
    }
}
