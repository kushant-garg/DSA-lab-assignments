#include <iostream>
#include <string>
using namespace std;

string concatenateStrings(string a, string b) {
    return a + b;
}

string reverseString(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        char temp = s[i];
        s[i] = s[n - 1 - i];
        s[n - 1 - i] = temp;
    }
    return s;
}

string deleteVowels(string s) {
    string r = "";
    for (char c : s) {
        if (c!='a' && c!='e' && c!='i' && c!='o' && c!='u' &&
            c!='A' && c!='E' && c!='I' && c!='O' && c!='U') 
            r += c;
    }
    return r;
}

void sortStrings(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

char toLowercase(char c) {
    if (c >= 'A' && c <= 'Z') return c + 32;
    return c;
}

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    cout << concatenateStrings(a, b) << endl;

    string s;
    getline(cin, s);
    cout << reverseString(s) << endl;

    getline(cin, s);
    cout << deleteVowels(s) << endl;

    int n;
    cin >> n;
    cin.ignore();
    string arr[n];
    for (int i = 0; i < n; i++) getline(cin, arr[i]);

    sortStrings(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << endl;

    char c;
    cin >> c;
    cout << toLowercase(c);
}
