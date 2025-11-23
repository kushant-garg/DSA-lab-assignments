#include <iostream>
using namespace std;

int main(){
    int n; 
    cin >> n;
    int a[200];
    for(int i=0;i<n;i++) cin >> a[i];

    for(int i=1;i<n;i++){
        int x = a[i], j = i - 1;
        while(j >= 0 && a[j] > x){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }

    for(int i=0;i<n;i++) cout << a[i] << " ";
}
