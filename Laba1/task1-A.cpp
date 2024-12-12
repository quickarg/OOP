#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for(int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Адрес начала массива: " << arr << endl;
    for(int i = 0; i < n; ++i) {
        cout << "Адрес[" << i << "]: " << &arr[i];
        cout << ", от начала: " << (char*)&arr[i] - (char*)arr << " байтов" << endl;
    }
    delete[] arr;
    return 0;
}