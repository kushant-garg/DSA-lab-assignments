#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n-1];
    for (int i = 0; i < n-1; i++) cin >> arr[i];

    for (int i = 0; i < n-1; i++) {
        if (arr[i] != i + 1) {
            cout << i + 1;
            return 0;
        }
    }
    cout << n;
}
