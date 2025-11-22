#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int target;
    cin >> target;

    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            cout << mid;
            return 0;
        }
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    cout << -1;
}
