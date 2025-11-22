#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "enter n: ";
    cin >> n;

    int arr[100];
    cout << "enter " << n << " elems: ";

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int distinct = 0;

    for(int i=0;i<n;i++){
        bool found = false;

        for(int j=0;j<i;j++){
            if(arr[i] == arr[j]){
                found = true;
                break;
            }
        }

        if(found == false){
            distinct++;
        }
    }

    cout << "totl distinct = " << distinct;

    return 0;
}
