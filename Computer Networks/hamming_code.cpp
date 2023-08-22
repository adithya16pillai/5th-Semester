#include <iostream>
#include <math.h>
using namespace std;

int main () {
    int a, b, c[30], d, r = 0, d1,err[10]={0}; 
    cout << "Enter the No of Data Bits: ";
    cin >> a;
    while (a + r + 1 > pow (2, r)) {
        r++;
    }
    cout << "No of redundant data bits to be added " << r << " : Total Bits(data+ redundant) :" << a +
    r << endl;
    cout << "Enter the Data:" << endl;
    for (int i = 1; i <= a; ++i)
        cin >> c[i];
    cout << endl << "Data bits entered: ";
    for (int i = 1; i <= a; ++i)
        cout << c[i] << " ";
    cout << endl;
    int data[a + r],res[a+r];
    d = 0;
    d1 = 1;
    for (int i = 1; i <= a + r; ++i) {
        if ((i) == pow (2, d)) {
            data[i] = 0;
            ++d;
        } else {
            data[i] = c[d1];
            ++d1;
        }
    }
    cout << "Data Bits are Encoded with Parity bits(0): ";
    for (int i = 1; i <= a + r; ++i)
        cout << data[i] << " ";
    d1 = 0;
    int min, max = 0, parity, s, j;
    for (int i = 1; i <= a + r; i = pow (2, d1)) {
        ++d1;
        parity = 0;
        j = i;
        s = i;
        min = 1;
        max = i;
        for (j; j <= a + r;) {
            for (s = j; max >= min && s <= a + r; ++min, ++s) {
                if (data[s] == 1)
                    parity++;
            }
        j = s + i;
        min = 1;
        }
        if (parity % 2 == 0) {
            data[i] = 0;
        } else {
            data[i] = 1;
        }
    }
    cout << endl << "Hamming codeword bits for even parity are : ";
    for (int i = 1; i <= a + r; ++i)
        cout << data[i] << " ";
    cout << endl << endl;
    cout<<"Enter the message receieved"<<endl;
    cout << endl;
    cout << "Enter the Data Bits:" << endl;
    for (int i = 1; i <= a+r; ++i)
        cin >> res[i];
    d1 = 0;max=0;int ec=0;
    for (int i = 1; i <= a + r; i = pow (2, d1)) {
        ++d1;
        parity = 0;
        j = i;
        s = i;
        min = 1;
        max = i;
        for (j; j <= a + r;) {
            for (s = j; max >= min && s <= a + r; ++min, ++s) {
                if (res[s] == 1)
                    parity++;
            }
        j = s + i;
        min = 1;
        }
        if (parity % 2 == 0){
            err[ec]=0;
            ec++;
        } else {
            err[ec]=1;
            ec++;
        }
    }
    int flag = 1;
    for(int i =r-1;i>=0;i--) {
        if(err[i]==1) {
            flag =0;
                break;
        }
    }
    if(flag==0) {
        int pos=0;
    cout<<"Error detected at: ";
    for(int i =r-1;i>=0;i--) {
        cout<<err[i]<<" ";
        if(err[i]==1)
            pos+=pow(2,i);
    }
    cout<<"\nPosition of error :"<<pos;
    res[pos]=!res[pos];
    cout<<"\nAfter correction: ";
    for(int i =1;i<=a+r;i++)
        cout<<res[i]<<" ";
    } else {
       cout<<"No Error detected. ";
    }
}
