#include <iostream>
using namespace std; 
int main() {
    int a[100], b[100], i, n, j, c = 0, p = 0;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter the elements: " << endl;
    for(i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    for(i = 0; i < n; i++) {
        if(a[i] == 0) {
            c++;
        } else {
            c = 0;
        }
        if(c == 5) {
            p++;
            n = n + 1;
            for(j = n - 1; j > i + 1; j--) {
                a[j] = a[j-1];
            }
            a[i+1] = 1;
        }
    }
    cout << "After bit stuffing the string is: " << endl;
    for(i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    n = n - p;
    cout << "After bit unstuffing the string is: " << endl;
    for(i = 0; i < n; i++) {    
        cout << b[i] << " ";
    }
}