#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n-1];
    for (int i = 0; i < n-1; i++) cin >> arr[i];

    int left = 0, right = n - 2;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == mid + 1) left = mid + 1;
        else right = mid - 1;
    }
    cout << left + 1;
}
