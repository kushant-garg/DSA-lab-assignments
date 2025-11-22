#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    double arr[1000];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int inv = 0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] > arr[j]){
                inv++;
            }
        }
    }

    cout << inv;
    return 0;
}
